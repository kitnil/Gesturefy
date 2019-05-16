import { toSingleButton } from "/core/commons.js";

// global static variables

const LEFT_MOUSE_BUTTON = 1;
const RIGHT_MOUSE_BUTTON = 2;
const MIDDLE_MOUSE_BUTTON = 4;

/**
 * WheelGestureController "singleton"
 * provides 2 events: on wheelup and wheeldown
 * events can be added via addEventListener and removed via removeEventListener
 * on default the controller is disabled and must be enabled via enable()
 **/


// public methods and variables


export default {
  enable: enable,
  disable: disable,
  addEventListener: addEventListener,
  hasEventListener: hasEventListener,
  removeEventListener: removeEventListener,

  get targetElement () {
    return targetElement;
  },
  set targetElement (value) {
    targetElement = value;
  },

  get mouseButton () {
    return mouseButton;
  },
  set mouseButton (value) {
    mouseButton = Number(value);
  }
}


/**
 * Add callbacks to the given events
 **/
function addEventListener (event, callback) {
  // if event exists add listener (duplicates won't be added)
  if (event in events) events[event].add(callback);
};


/**
 * Check if an event listener is registered
 **/
function hasEventListener (event, callback) {
  // if event exists check for listener
  if (event in events) events[event].has(callback);
};


/**
 * Remove callbacks from the given events
 **/
function removeEventListener (event, callback) {
  // if event exists remove listener
  if (event in events) events[event].delete(callback);
};


/**
 * Add the document event listener
 **/
function enable () {
  targetElement.addEventListener('wheel', handleWheel, true);
  targetElement.addEventListener('mousedown', handleMousedown, true);
  targetElement.addEventListener('mouseup', handleMouseup, true);
  targetElement.addEventListener('click', handleClick, true);
  targetElement.addEventListener('contextmenu', handleContextmenu, true);
  targetElement.addEventListener('visibilitychange', handleVisibilitychange, true);
};


/**
 * Remove the event listeners and resets the handler
 **/
function disable () {
  preventDefault = true;
  targetElement.removeEventListener('wheel', handleWheel, true);
  targetElement.removeEventListener('mousedown', handleMousedown, true);
  targetElement.removeEventListener('mouseup', handleMouseup, true);
  targetElement.removeEventListener('click', handleClick, true);
  targetElement.removeEventListener('contextmenu', handleContextmenu, true);
  targetElement.removeEventListener('visibilitychange', handleVisibilitychange, true);
}

// private variables and methods

// holds all custom module event callbacks
const events = {
  'wheelup': new Set(),
  'wheeldown': new Set()
};

let targetElement = window,
    mouseButton = LEFT_MOUSE_BUTTON;

// keep preventDefault true for the special case that the contextmenu or click is fired without a privious mousedown
let preventDefault = true;

let lastMouseup = 0;


/**
 * Handles mousedown which will detect the target and handle prevention
 **/
function handleMousedown (event) {
  if (event.isTrusted && event.buttons === mouseButton) {
    // always disable prevention on mousedown
    preventDefault = false;

    // prevent middle click scroll
    if (mouseButton === MIDDLE_MOUSE_BUTTON) event.preventDefault();
  }
}


/**
 * Handles mousewheel up and down and prevents scrolling if needed
 **/
function handleWheel (event) {
  if (event.isTrusted && event.buttons === mouseButton && event.deltaY !== 0) {
    // dispatch all binded functions on wheel and pass the appropriate event
    if (event.deltaY < 0) events['wheelup'].forEach((callback) => callback(event));
    else if (event.deltaY > 0) events['wheeldown'].forEach((callback) => callback(event));

    event.stopPropagation();
    event.preventDefault();
    // enable prevention
    preventDefault = true;
  }
}


/**
 * This is only needed to distinguish between true mouse click events and other click events fired by pressing enter or by clicking labels
 * Other property values like screen position or target could be used in the same manner
 **/
function handleMouseup(event) {
  lastMouseup = event.timeStamp;
}


/**
 * This is only needed for tab changing actions
 * Because the wheel gesture is executed in a different tab as where click/contextmenu needs to be prevented
 **/
function handleVisibilitychange() {
  // keep preventDefault true for the special case that the contextmenu or click is fired without a privious mousedown
  preventDefault = true;
}


/**
 * Handles and prevents context menu if needed
 **/
function handleContextmenu (event) {
  if (event.isTrusted && preventDefault && event.button === toSingleButton(mouseButton) && mouseButton === RIGHT_MOUSE_BUTTON) {
    // prevent contextmenu
    event.stopPropagation();
    event.preventDefault();
  }
}


/**
 * Handles and prevents click event if needed
 **/
function handleClick (event) {
  // event.detail because a click event can be fired without clicking (https://stackoverflow.com/questions/4763638/enter-triggers-button-click)
  // timeStamp check ensures that the click is fired by mouseup
  if (event.isTrusted && preventDefault && event.button === toSingleButton(mouseButton) && (mouseButton === LEFT_MOUSE_BUTTON || mouseButton === MIDDLE_MOUSE_BUTTON) && event.detail && event.timeStamp === lastMouseup) {
    // prevent left and middle click
    event.stopPropagation();
    event.preventDefault();
  }
}