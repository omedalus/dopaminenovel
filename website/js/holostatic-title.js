/**
 * Renders an animated vibrating title that looks like an unstable hologram.
 * Copyright 2014 (C) Mikhail Voloshin. All rights reserved.
 */

(function() {

var is_firefox = navigator.userAgent.toLowerCase().indexOf('firefox') > -1;

var DOPAMINE_TITLE_TEXT_IMG = new Image();
DOPAMINE_TITLE_TEXT_IMG.src = "data:image/png;base64,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";
 
var canvas;
var drawingCtx;
var text;

var animationIntervalMinFrames = 0;
var animationIntervalMaxFrames = 300;
var frameMs = 30;

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
  var totalTimeWaited = 0;
  
  var keepWaiting = function() {
    totalTimeWaited += frameMs;
  
    var nowWidth = fontElem.offsetWidth;
    
    if ((elemWidth && elemWidth !== nowWidth) || totalTimeWaited > 3000) {
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
  drawingCtx.drawImage(DOPAMINE_TITLE_TEXT_IMG, 0, 0);
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
  var lineToDisplace = (relFrame / 100) * canvas.height;
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
  var lineToDisplace = (relFrame / 100) * canvas.width;
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

var animFlashMagnify = function(relFrame) {
  var magnifyFactor = (relFrame / 100);
  
  renderPlain();

  drawingCtx.globalAlpha = 1 - magnifyFactor;
  drawingCtx.translate(-canvas.width * magnifyFactor / 2, -canvas.height * magnifyFactor / 2);
  drawingCtx.scale(1 + magnifyFactor, 1 + magnifyFactor);
  renderPlain();

  return magnifyFactor < 1;
};
animations.push(animFlashMagnify);

var animBlockBlank = function(relFrame) {
  var numFrames = 100;
  var blockSize = 10;
  
  var blockOutRatio = 1 - Math.pow(relFrame / numFrames, 3);
  
  renderPlain();
  
  for (var y = 0; y < canvas.height; y += blockSize) {
    for (var x = 0; x < canvas.width; x += blockSize) {
      if (Math.random() < blockOutRatio) {
        continue;
      }
      
      drawingCtx.clearRect(x, y, blockSize, blockSize);
    }
  }
  
  return relFrame < numFrames;
};
animations.push(animBlockBlank);

var animGrowStretch = function(relFrame) {
  var numFrames = 150;
  var xScaleDelta = (.05 * Math.sin(2 * Math.PI * relFrame / numFrames));
  var yScaleDelta = (.05 * Math.sin(3 * Math.PI * relFrame / numFrames));

  drawingCtx.translate(-xScaleDelta * canvas.width / 2, -yScaleDelta * canvas.height / 2);
  drawingCtx.scale(1 + xScaleDelta, 1 + yScaleDelta);
  renderPlain();
  
  return relFrame < numFrames * 3;
};
animations.push(animGrowStretch);

var animFadeOut = function(relFrame) {
  var numFrames = 150;
  var deadFrames = 10;
  var halfNumFrames = numFrames / 2;

  if (relFrame < halfNumFrames) {
    if (Math.random() < .8) {
      renderPlain();
    }
  } else if (relFrame < numFrames) {
    drawingCtx.globalAlpha = 1 - ((relFrame - halfNumFrames) / halfNumFrames);
    renderPlain();
  }
  
  return relFrame < numFrames + deadFrames;
};
animations.push(animFadeOut);


var runAnimation;
(function() {
  var frame = 0;
  var frameNextAnimStarts = frame;
    
  var currentAnim;
  var frameCurrentAnimStarted;

  runAnimation = function() {
    // Clear canvas AND reset all state.
    canvas.width = canvas.width;
    
    // Create the hovering animation.
    //translateHover(frame);
    
    if (!currentAnim && frame >= frameNextAnimStarts) {
      currentAnim = animations[Math.floor(animations.length * Math.random())];
      frameCurrentAnimStarted = frame;
    }

    var animToUse = currentAnim || renderPlain;
    
    var continueAnimation = animToUse(frame - frameCurrentAnimStarted);
    frame++;
    
    if (!continueAnimation) {
      currentAnim = null;
      frameNextAnimStarts = frame + nextTimeoutPeriod();
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
  element.style.position = 'relative';
  element.style.height = '64px';
  element.style.width = '400px';
  element.style.display = 'inline-block';
  
  canvas.style.opacity = .9;
  canvas.style.position = 'absolute';
  canvas.style.top = '-10px';
  canvas.style.right = '-50px';
  
  canvas.width = 450;
  canvas.height = 74;

  waitForFontToLoad('Research', runAnimation);
});

})();
