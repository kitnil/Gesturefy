<template data-commands="SaveImage SaveLink">
  <span data-i18n="commandSettingLabelSavePromptDialog" class="cb-setting-name"></span>
  <input name="promptDialog" id="CommandSettingSavePromptDialog" class="toggle-button" type="checkbox">
  <label for="CommandSettingSavePromptDialog"></label>
  <p data-i18n="commandSettingDescriptionSavePromptDialog" class="cb-setting-description"></p>
</template>

<template data-commands="MoveLeftTabsToNewWindow MoveRightTabsToNewWindow">
  <span data-i18n="commandSettingLabelNewWindowFocus" class="cb-setting-name"></span>
  <input name="focus" id="CommandSettingNewWindowFocus" class="toggle-button" type="checkbox">
  <label for="CommandSettingNewWindowFocus"></label>
  <p data-i18n="commandSettingDescriptionNewWindowFocus" class="cb-setting-description"></p>
</template>

<template data-commands="MoveLeftTabsToNewWindow MoveRightTabsToNewWindow">
  <span data-i18n="commandSettingLabelTabIncludeCurrent" class="cb-setting-name"></span>
  <input name="includeCurrent" id="CommandSettingTabIncludeCurrent" class="toggle-button" type="checkbox">
  <label for="CommandSettingTabIncludeCurrent"></label>
  <p data-i18n="commandSettingDescriptionTabIncludeCurrent" class="cb-setting-description"></p>
</template>

<template data-commands="SearchTextSelection SearchClipboard">
  <span data-i18n="commandSettingLabelSearchEngineURL" class="cb-setting-name"></span>
  <p data-i18n="commandSettingDescriptionSearchEngineURL" class="cb-setting-description"></p>
  <input name="searchEngineURL" class="input-field" type="url">
</template>

<template data-commands="OpenCustomURL OpenCustomURLInNewTab">
  <span data-i18n="commandSettingLabelCustomURL" class="cb-setting-name"></span>
  <p data-i18n="commandSettingDescriptionCustomURL" class="cb-setting-description"></p>
  <input name="url" class="input-field" required="" type="url">
</template>

<template data-commands="NewTab DuplicateTab OpenLinkInNewTab OpenImageInNewTab SearchTextSelection SearchClipboard PopupSearchEngines OpenCustomURLInNewTab OpenURLFromClipboardInNewTab">
  <span data-i18n="commandSettingLabelNewTabPosition" class="cb-setting-name"></span>
  <p data-i18n="commandSettingDescriptionNewTabPosition" class="cb-setting-description"></p>
  <div class="select-wrapper">
    <select name="position" class="select-field">
      <option value="default" data-i18n="commandSettingLabelNewTabPositionDefault"></option>
      <option value="after" data-i18n="commandSettingLabelNewTabPositionAfter"></option>
      <option value="before" data-i18n="commandSettingLabelNewTabPositionBefore"></option>
      <option value="end" data-i18n="commandSettingLabelNewTabPositionEnd"></option>
      <option value="start" data-i18n="commandSettingLabelNewTabPositionStart"></option>
    </select>
  </div>
</template>

<template data-commands="NewTab DuplicateTab OpenImageInNewTab OpenLinkInNewTab SearchTextSelection SearchClipboard OpenCustomURLInNewTab OpenURLFromClipboardInNewTab">
  <span data-i18n="commandSettingLabelNewTabFocus" class="cb-setting-name"></span>
  <input name="focus" id="CommandSettingTabFocus" class="toggle-button" type="checkbox">
  <label for="CommandSettingTabFocus"></label>
  <p data-i18n="commandSettingDescriptionNewTabFocus" class="cb-setting-description"></p>
</template>

<template data-commands="CloseTab">
  <span data-i18n="commandSettingLabelTabNextFocus" class="cb-setting-name"></span>
  <p data-i18n="commandSettingDescriptionTabNextFocus" class="cb-setting-description"></p>
  <div class="select-wrapper">
    <select name="nextFocus" class="select-field">>
      <option value="default" data-i18n="commandSettingLabelTabNextFocusDefault"></option>
      <option value="previous" data-i18n="commandSettingLabelTabNextFocusPrevious"></option>
      <option value="next" data-i18n="commandSettingLabelTabNextFocusNext"></option>
      <option value="recent" data-i18n="commandSettingLabelTabNextFocusRecently"></option>
    </select>
  </div>
</template>

<template data-commands="CloseTab">
  <span data-i18n="commandSettingLabelTabClosePinned" class="cb-setting-name"></span>
  <input name="closePinned" id="CommandSettingTabClosePinned" class="toggle-button" type="checkbox">
  <label for="CommandSettingTabClosePinned"></label>
  <p data-i18n="commandSettingDescriptionTabClosePinned" class="cb-setting-description"></p>
</template>

<template data-commands="RestoreTab">
  <span data-i18n="commandSettingLabelRestoreCurrentWindow" class="cb-setting-name"></span>
  <input name="currentWindowOnly" id="CommandSettingRestoreCurrentWindow" class="toggle-button" type="checkbox">
  <label for="CommandSettingRestoreCurrentWindow"></label>
  <p data-i18n="commandSettingDescriptionRestoreCurrentWindow" class="cb-setting-description"></p>
</template>

<template data-commands="ReloadTab ReloadFrame ReloadAllTabs">
  <span data-i18n="commandSettingLabelReloadCache" class="cb-setting-name"></span>
  <input name="cache" id="CommandSettingReloadCache" class="toggle-button" type="checkbox">
  <label for="CommandSettingReloadCache"></label>
  <p data-i18n="commandSettingDescriptionReloadCache" class="cb-setting-description"></p>
</template>

<template data-commands="ZoomIn ZoomOut">
  <span data-i18n="commandSettingLabelZoomStep" class="cb-setting-name"></span>
  <p data-i18n="commandSettingDescriptionZoomStep" class="cb-setting-description"></p>
  <input name="step" class="input-field" pattern="^\d+(\s*,\s*\d+)*$" type="text">
</template>

<template data-commands="ScrollTop ScrollBottom ScrollPageDown ScrollPageUp">
  <span data-i18n="commandSettingLabelScrollDuration" class="cb-setting-name"></span>
  <p data-i18n="commandSettingDescriptionScrollDuration" class="cb-setting-description"></p>
  <input name="duration" class="input-field" required="" step="1" max="5000" min="0" type="number">
</template>

<template data-commands="FocusFirstTab">
  <span data-i18n="commandSettingLabelFocusIncludePinned" class="cb-setting-name"></span>
  <input name="includePinned" id="CommandSettingFocusIncludePinned" class="toggle-button" type="checkbox">
  <label for="CommandSettingFocusIncludePinned"></label>
  <p data-i18n="commandSettingDescriptionFocusIncludePinned" class="cb-setting-description"></p>
</template>

<template data-commands="FocusRightTab FocusLeftTab">
  <span data-i18n="commandSettingLabelTabCycling" class="cb-setting-name"></span>
  <input name="cycling" id="CommandSettingTabCycling" class="toggle-button" type="checkbox">
  <label for="CommandSettingTabCycling"></label>
  <p data-i18n="commandSettingDescriptionTabCycling" class="cb-setting-description"></p>
</template>

<template data-commands="FocusRightTab FocusLeftTab">
  <span data-i18n="commandSettingLabelExcludeDiscarded" class="cb-setting-name"></span>
  <input name="excludeDiscarded" id="CommandSettingExcludeDiscarded" class="toggle-button" type="checkbox">
  <label for="CommandSettingExcludeDiscarded"></label>
  <p data-i18n="commandSettingDescriptionExcludeDiscarded" class="cb-setting-description"></p>
</template>

<template data-commands="OpenLinkInNewTab">
  <span data-i18n="commandSettingLabelOpenEmptyTab" class="cb-setting-name"></span>
  <input name="emptyTab" id="CommandSettingToEmptyTab" class="toggle-button" type="checkbox">
  <label for="CommandSettingToEmptyTab"></label>
  <p data-i18n="commandSettingDescriptionOpenEmptyTab" class="cb-setting-description"></p>
</template>

<template data-commands="OpenLinkInNewWindow OpenLinkInNewPrivateWindow">
  <span data-i18n="commandSettingLabelOpenEmptyWindow" class="cb-setting-name"></span>
  <input name="emptyWindow" id="CommandSettingToEmptyWindow" class="toggle-button" type="checkbox">
  <label for="CommandSettingToEmptyWindow"></label>
  <p data-i18n="commandSettingDescriptionOpenEmptyWindow" class="cb-setting-description"></p>
</template>

<template data-commands="SendMessageToOtherAddon">
  <span data-i18n="commandSettingLabelAddonId" class="cb-setting-name"></span>
  <p class="cb-setting-description">
    <span data-i18n="commandSettingDescriptionAddonId"></span>
    <a target="_blank" href="https://github.com/Robbendebiene/Gesturefy/wiki/Send-message-to-other-addon" data-i18n="linkAdditionalInformation"></a>
  </p>
  <input name="extensionId" class="input-field" required="" type="text">
</template>

<template data-commands="SendMessageToOtherAddon">
  <span data-i18n="commandSettingLabelAddonMessage" class="cb-setting-name"></span>
  <p data-i18n="commandSettingDescriptionAddonMessage" class="cb-setting-description"></p>
  <textarea name="message" class="text-field" required=""></textarea>
</template>

<template data-commands="SendMessageToOtherAddon">
  <span data-i18n="commandSettingLabelParseMessage" class="cb-setting-name"></span>
  <input name="parseJSON" id="CommandSettingToEmptyTab" class="toggle-button" type="checkbox">
  <label for="CommandSettingToEmptyTab"></label>
  <p data-i18n="commandSettingDescriptionParseMessage" class="cb-setting-description"></p>
</template>

<template data-commands="PopupAllTabs">
  <span data-i18n="commandSettingLabelTabOrder" class="cb-setting-name"></span>
  <p data-i18n="commandSettingDescriptionTabOrder" class="cb-setting-description"></p>
  <div class="select-wrapper">
    <select name="order" class="select-field">
      <option value="none" data-i18n="commandSettingLabelTabOrderNone"></option>
      <option value="lastAccessedAsc" data-i18n="commandSettingLabelTabOrderLastAccessedAsc"></option>
      <option value="lastAccessedDesc" data-i18n="commandSettingLabelTabOrderLastAccessedDesc"></option>
      <option value="alphabeticalAsc" data-i18n="commandSettingLabelTabOrderAlphabeticallyAsc"></option>
      <option value="alphabeticalDesc" data-i18n="commandSettingLabelTabOrderAlphabeticallyDesc"></option>
    </select>
  </div>
</template>

<template data-commands="ExecuteUserScript">
  <span data-i18n="commandSettingLabelUserScriptWarning" class="cb-setting-name warning-text"></span>
  <p class="cb-setting-description warning-text">
    <span data-i18n="commandSettingDescriptionUserScriptWarning"></span>
    <a target="_blank" href="https://github.com/Robbendebiene/Gesturefy/wiki/Execute-user-script" data-i18n="linkAdditionalInformation" class="warning-text"></a>
  </p>
</template>

<template data-commands="ExecuteUserScript">
  <span data-i18n="commandSettingLabelUserScriptCode" class="cb-setting-name"></span>
  <p data-i18n="commandSettingDescriptionUserScriptCode" class="cb-setting-description"></p>
  <textarea name="userScript" class="text-field" required=""></textarea>
</template>

<template data-commands="ExecuteUserScript">
  <span data-i18n="commandSettingLabelTargetFrame" class="cb-setting-name"></span>
  <p data-i18n="commandSettingDescriptionTargetFrame" class="cb-setting-description"></p>
  <div class="select-wrapper">
    <select name="targetFrame" class="select-field">
      <option value="sourceFrame" data-i18n="commandSettingLabelTargetFrameSourceFrame"></option>
      <option value="allFrames" data-i18n="commandSettingLabelTargetFrameAllFrames"></option>
      <option value="topFrame" data-i18n="commandSettingLabelTargetFrameTopFrame"></option>
    </select>
  </div>
</template>

<template data-commands="ClearBrowsingData">
  <span data-i18n="commandSettingLabelBrowsingDataCache" class="cb-setting-name"></span>
  <input name="cache" id="CommandSettingBrowsingDataCache" class="toggle-button" type="checkbox">
  <label for="CommandSettingBrowsingDataCache"></label>
</template>

<template data-commands="ClearBrowsingData">
  <span data-i18n="commandSettingLabelBrowsingDataCookies" class="cb-setting-name"></span>
  <input name="cookies" id="CommandSettingBrowsingDataCookies" class="toggle-button" type="checkbox">
  <label for="CommandSettingBrowsingDataCookies"></label>
</template>

<template data-commands="ClearBrowsingData">
  <span data-i18n="commandSettingLabelBrowsingDataDownloads" class="cb-setting-name"></span>
  <input name="downloads" id="CommandSettingBrowsingDataDownloads" class="toggle-button" type="checkbox">
  <label for="CommandSettingBrowsingDataDownloads"></label>
</template>

<template data-commands="ClearBrowsingData">
  <span data-i18n="commandSettingLabelBrowsingDataFormData" class="cb-setting-name"></span>
  <input name="formData" id="CommandSettingBrowsingDataFormData" class="toggle-button" type="checkbox">
  <label for="CommandSettingBrowsingDataFormData"></label>
</template>

<template data-commands="ClearBrowsingData">
  <span data-i18n="commandSettingLabelBrowsingDataHistory" class="cb-setting-name"></span>
  <input name="history" id="CommandSettingBrowsingDataHistory" class="toggle-button" type="checkbox">
  <label for="CommandSettingBrowsingDataHistory"></label>
</template>

<template data-commands="ClearBrowsingData">
  <span data-i18n="commandSettingLabelBrowsingDataIndexedDB" class="cb-setting-name"></span>
  <input name="indexedDB" id="CommandSettingBrowsingDataIndexedDB" class="toggle-button" type="checkbox">
  <label for="CommandSettingBrowsingDataIndexedDB"></label>
</template>

<template data-commands="ClearBrowsingData">
  <span data-i18n="commandSettingLabelBrowsingDataLocalStorage" class="cb-setting-name"></span>
  <input name="localStorage" id="CommandSettingBrowsingDataLocalStorage" class="toggle-button" type="checkbox">
  <label for="CommandSettingBrowsingDataLocalStorage"></label>
</template>

<template data-commands="ClearBrowsingData">
  <span data-i18n="commandSettingLabelBrowsingDataPasswords" class="cb-setting-name"></span>
  <input name="passwords" id="CommandSettingBrowsingDataPasswords" class="toggle-button" type="checkbox">
  <label for="CommandSettingBrowsingDataPasswords"></label>
</template>

<template data-commands="ClearBrowsingData">
  <span data-i18n="commandSettingLabelBrowsingDataPluginData" class="cb-setting-name"></span>
  <input name="pluginData" id="CommandSettingBrowsingDataPluginData" class="toggle-button" type="checkbox">
  <label for="CommandSettingBrowsingDataPluginData"></label>
</template>

<template data-commands="ClearBrowsingData">
  <span data-i18n="commandSettingLabelBrowsingDataServiceWorkers" class="cb-setting-name"></span>
  <input name="serviceWorkers" id="CommandSettingBrowsingDataServiceWorkers" class="toggle-button" type="checkbox">
  <label for="CommandSettingBrowsingDataServiceWorkers"></label>
</template>