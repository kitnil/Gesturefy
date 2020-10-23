import { fetchHTMLAsFragment } from "/core/commons.js";

import ConfigManager from "/core/config-manager.js";

export const Config = new ConfigManager("local", browser.runtime.getURL("/resources/json/defaults.json"));


const Resources = [ Config.loaded ];

// load and insert external html fragments
for (let element of document.querySelectorAll('[data-include]')) {
  const fetchingHTML = fetchHTMLAsFragment(browser.runtime.getURL(element.dataset.include));
        fetchingHTML.then((fragment) => element.appendChild(fragment));
  // add to resources
  Resources.push(fetchingHTML);
}

export const ContentLoaded = Promise.all(Resources);

ContentLoaded.then(main);

/**
 * main function
 * run code that depends on async resources
 **/
function main () {
  // insert text from manifest
  const manifest = browser.runtime.getManifest();
  for (let element of document.querySelectorAll('[data-manifest]')) {
    element.textContent = manifest[element.dataset.manifest];
  }

  // insert text from language files
  for (let element of document.querySelectorAll('[data-i18n]')) {
    element.textContent = browser.i18n.getMessage(element.dataset.i18n);
  }

  // apply onchange handler and add title to every theme button
  for (let themeButton of document.querySelectorAll('#themeSwitch .theme-button')) {
    const input = document.getElementById(themeButton.htmlFor);
          input.onchange = onThemeButtonChange;
    themeButton.title = browser.i18n.getMessage(`${input.value}Theme`);
  }
  // apply theme
  const themeValue = Config.get("Settings.General.theme");
  const themeStylesheet = document.getElementById("Theme");
        themeStylesheet.href = `/views/options/css/themes/${themeValue}.css`;
  // set corresponding theme button as active
  const themeSwitchForm = document.getElementById('themeSwitch');
        themeSwitchForm.theme.value = themeValue;

  // set default page if not specified and trigger page navigation handler
  window.addEventListener("hashchange", onPageNavigation, true);
  if (!window.location.hash) location.replace('#Settings');
  else onPageNavigation();
}


/**
 * on hash change / page navigation
 * updates the document title and navbar
 **/
function onPageNavigation () {
  // update the navbar entries highlighting
  const activeItem = document.querySelector('#Sidebar .navigation .nav-item > a.active');
  const nextItem = document.querySelector('#Sidebar .navigation .nav-item > a[href="'+ window.location.hash +'"]');

  if (activeItem) activeItem.classList.remove("active");
  if (nextItem) {
    nextItem.classList.add("active");
    // update document title
    const sectionKey = nextItem.querySelector("[data-i18n]").dataset.i18n;
    document.title = `Gesturefy - ${browser.i18n.getMessage(sectionKey)}`;
  }
}


/**
* on theme/radio button change
* store the new theme
**/
function onThemeButtonChange () {
  // store theme in the config
  Config.set("Settings.General.theme", this.value);
  // create temporary transition for all elements
  const transitionStyle = document.createElement("style");
        transitionStyle.appendChild( document.createTextNode("* {transition: all .3s !important;}") );
  // apply transition to main document
  document.head.appendChild(transitionStyle);
  // set theme to document
  document.getElementById('Theme').href=`/views/options/css/themes/${this.value}.css`;
  // remove temporary transition
  window.setTimeout(() => {
    transitionStyle.remove();
  }, 400);
}
