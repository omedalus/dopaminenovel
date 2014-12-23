/**
 * Renders an animated vibrating title that looks like an unstable hologram.
 * Copyright 2014 (C) Mikhail Voloshin. All rights reserved.
 */

(function() {
 
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
  drawingCtx.font = 'small-caps bold 64px Research';
  drawingCtx.textAlign = 'right';
  
  drawingCtx.strokeStyle = 'rgba(60, 160, 100, .6)';
  drawingCtx.lineWidth = 8;
  drawingCtx.strokeText(text, 400, 58);

  drawingCtx.fillStyle = '#fff';
  
  if ($(canvas.parentNode).is(':hover')) {
    drawingCtx.fillStyle = '#ff0';
  }
  
  drawingCtx.fillText(text, 400, 57);
  
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
  
  canvas.style.opacity = .9;
  canvas.style.position = 'absolute';
  canvas.style.top = '-10px';
  canvas.style.right = '-50px';
  
  canvas.width = 450;
  canvas.height = 74;

  waitForFontToLoad('Research', runAnimation);
});

})();
