/**
 * Renders an animated vibrating title that looks like an unstable hologram.
 * Copyright 2014 (C) Mikhail Voloshin. All rights reserved.
 */

(function() {
 
var canvas;
var drawingCtx;
var text;

var animationIntervalMinFrames = 30;
var animationIntervalMaxFrames = 100;
var frameMs = 50;

var animations = [];

var nextTimeoutPeriod = function() {
  return animationIntervalMinFrames + (Math.random() * (animationIntervalMaxFrames - animationIntervalMinFrames));
};

var waitForFontToLoad = function(fontName, fnWhenLoaded) {
  var fontElem = document.createElement('span');
  fontElem.style.fontFamily = fontName;
  fontElem.style.opacity = 0;
  document.body.appendChild(fontElem);
  fontElem.innerHTML = '___';
  
  var elemWidth;
  var keepWaiting = function() {
    var nowWidth = fontElem.offsetWidth;
    
    if (elemWidth && elemWidth !== nowWidth) {
      // The font was something before, but now it's changed. That must mean
      // that it's finished loading.
      document.body.removeChild(fontElem);
      fnWhenLoaded();
    } else {
      elemWidth = nowWidth;    
      setTimeout(keepWaiting, frameMs);
    }
  };
  keepWaiting();
};

var renderPlain = function() {
  drawingCtx.font = 'small-caps bold 64px Research';
  drawingCtx.textAlign = 'right';
  
  drawingCtx.strokeStyle = 'rgba(60, 160, 100, .6)';
  drawingCtx.lineWidth = 8;
  drawingCtx.strokeText(text, 400, 48);

  drawingCtx.fillStyle = 'white';
  drawingCtx.fillText(text, 400, 48);
  
  return true;
}

var translateHover = function(relframe) {
  var yOff = 5 + 5 * Math.sin(Math.PI * relframe / 101);

  var xScaleDiff = 1 + Math.cos(Math.PI * relframe / 57);
  var xScaleFactor = 1 + (xScaleDiff / 80);

  drawingCtx.translate(-10, yOff);
  drawingCtx.scale(xScaleFactor, 1);
};

var animGradualHorizontalBleed = function(relFrame) {
  var lineToDisplace = (relFrame / 20) * canvas.height;
  var firstLineToDisplace = lineToDisplace;
  var lineIntervals = [];
  for (var i = 0; i < 2 + Math.floor(Math.random() * 5); i++) {
    lineToDisplace = Math.floor(lineToDisplace);
    lineIntervals.push(lineToDisplace);
    lineToDisplace += 3 + Math.random() * 10;
  };
  
  renderPlain();
  for (var i = 0; i < lineIntervals.length; i++) {
    drawingCtx.clearRect(0, lineIntervals[i], canvas.width, 2);
  }

  drawingCtx.translate(-30, 0);

  drawingCtx.rect(0, firstLineToDisplace, canvas.width, 2);
  drawingCtx.clip();

  renderPlain();

  return firstLineToDisplace < canvas.height;
};
animations.push(animGradualHorizontalBleed);

var animGradualVerticalMagnify = function(relFrame) {
  var lineToDisplace = (relFrame / 30) * canvas.width;
  var blockWidth = 10 + Math.random() * 10;
  
  renderPlain();
  drawingCtx.clearRect(lineToDisplace, 0, blockWidth, canvas.height);

  drawingCtx.rect(lineToDisplace, 0, blockWidth, canvas.height);
  drawingCtx.clip();

  drawingCtx.scale(1.2, 1.2);
  drawingCtx.translate(lineToDisplace * -.1, canvas.height * -.1);
  renderPlain();

  return lineToDisplace < canvas.width;
};
animations.push(animGradualVerticalMagnify);

var runAnimation;
(function() {
  var frame = 0;
  var frameNextAnimStarts;
    
  var currentAnim;
  var frameCurrentAnimStarted;

  runAnimation = function() {
    // Clear canvas AND reset all state.
    canvas.width = canvas.width;
    
    // Create the hovering animation.
    translateHover(frame);
    
    if (!currentAnim || frame >= frameNextAnimStarts) {
      currentAnim = animations[Math.floor(animations.length * Math.random())];
    
      frameCurrentAnimStarted = frame;
      frameNextAnimStarts = frame + nextTimeoutPeriod();
    }

    var continueAnimation = currentAnim(frame - frameCurrentAnimStarted);
    frame++;
    
    if (!continueAnimation) {
      currentAnim = renderPlain;
    }
  
    setTimeout(function() {
      runAnimation();
    }, frameMs);
  };

})();

///////////////////////////////////////////////////
// Doc ready.

$(document).ready(function() {
  var element = document.getElementById("holostatic-title");
  text = element.innerText || element.textContent;

  canvas = document.createElement('canvas');
  drawingCtx = canvas.getContext('2d');
  drawingCtx.save();

  element.innerHTML = '';
  element.appendChild(canvas);
  element.style.textAlign = 'right';
  canvas.style.opacity = .9;
  
  canvas.width = 400;
  canvas.height = 64;

  waitForFontToLoad('Research', runAnimation);
});

})();