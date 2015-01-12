/**
 * Renders an animated vibrating title that looks like an unstable hologram.
 * Copyright 2014 (C) Mikhail Voloshin. All rights reserved.
 */

(function() {

var is_firefox = navigator.userAgent.toLowerCase().indexOf('firefox') > -1;

var DOPAMINE_TITLE_TEXT_IMG = new Image();
DOPAMINE_TITLE_TEXT_IMG.src = "data:image/png;base64,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"
 
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

var renderHovering = function() {
  drawingCtx.translate(-canvas.width * .025, -canvas.height * .025);
  drawingCtx.scale(1.05, 1.05);

  return renderPlain();
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
    
    if (!currentAnim && frame >= frameNextAnimStarts) {
      currentAnim = animations[Math.floor(animations.length * Math.random())];
      frameCurrentAnimStarted = frame;
    }

    var animToUse = currentAnim || renderPlain;

    // If we're being hovered over, everything else stops.
    if ($(canvas.parentNode).is(':hover')) {
      renderHovering();
    } else {
      var continueAnimation = animToUse(frame - frameCurrentAnimStarted);
      frame++;

      if (!continueAnimation) {
        currentAnim = null;
        frameNextAnimStarts = frame + nextTimeoutPeriod();
      }
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
