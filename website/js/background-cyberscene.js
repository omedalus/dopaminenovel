/**
 * Renders an animated background of green flashing bubbles and a circuitboard.
 * Copyright 2014 (C) Mikhail Voloshin. All rights reserved.
 */

var layers = {};

var layerDepths = {
  BUBBLES: 0,
  GRID_STATIC: 2,
  GRID_ANIMATED: 1
};

var animateBubbles;
var setupCircuitGrid;
var animateCircuitGrid;

/**
 * Add a hashcode method to String so that we can stably generate a stable circuit grid.
 */
String.prototype.hashCode = function() {
  var hash = 0, i, chr, len;
  if (this.length == 0) return hash;
  for (i = 0, len = this.length; i < len; i++) {
    chr   = this.charCodeAt(i);
    hash  = ((hash << 5) - hash) + chr;
    hash |= 0; // Convert to 32bit integer
  }
  return hash;
};

(function() {
  var Bubbles = [];
  var NUM_BUBBLES = 60;
  var BUBBLE_SIZE = .2;
  var BUBBLE_DRIFT_RATE_PER_FRAME = .002;
  var FLASH_PROBABILITY_PER_FRAME = 0.0005;
  var FLASH_DURATION_FRAMES = 100;

  var genOffs = function(minVal, maxVal, numSteps) {
    var step = (maxVal - minVal) / numSteps;
  
    var retval = [];
    for (var t = minVal; t <= maxVal; t += step) {
      retval.push(t);
    }

    // Knuth shuffling algo.
    for (var i = retval.length - 1; i > 1; i--) {
      var iShuffle = Math.floor(Math.random() * (i - 1));
      var placeholder = retval[i];
      retval[i] = retval[iShuffle];
      retval[iShuffle] = placeholder;
    }

    return retval;
  }
  
  var yOffs = genOffs(-.5, .5, NUM_BUBBLES);
  var xOffs = genOffs(-1, 1, NUM_BUBBLES);
  var bubbleSizes = genOffs(.2, 1, NUM_BUBBLES);
  var driftSpeeds = genOffs(.2, 1, NUM_BUBBLES);
  
  for (var iBubble = 0; iBubble < NUM_BUBBLES; iBubble++) {
    var BubbleObj = {};
    
    BubbleObj.viewportScale = {
      x: xOffs.pop(),
      y: yOffs.pop()
    };
    
    console.log(BubbleObj.viewportScale);
    
    BubbleObj.flashProgress = 0;    
    BubbleObj.objectScale = bubbleSizes.pop();
    BubbleObj.drift = Math.pow(driftSpeeds.pop(), 3); // Power it, otherwise it's too uniform.
    
    Bubbles.push(BubbleObj);
  }

  animateBubbles = function() {
    var canvas = layers.BUBBLES.canvas;
    var drawingCtx = layers.BUBBLES.drawingCtx;
    
    var yScrollRatio = window.scrollY / $(document).height();
  
    drawingCtx.clearRect(0, 0, canvas.width, canvas.height);
  
    for (var iBubble = 0; iBubble < Bubbles.length; iBubble++) {
      var BubbleObj = Bubbles[iBubble];
 
      var usingYScale = BubbleObj.viewportScale.y - (yScrollRatio * BUBBLE_SIZE);
 
      var renderX = (.5 + BubbleObj.viewportScale.x) * canvas.width;
      var renderY = (.5 + usingYScale) * canvas.height;

      var radiusBase = Math.min(canvas.width, canvas.height);
      var radius = radiusBase * BUBBLE_SIZE * BubbleObj.objectScale;

      drawingCtx.beginPath();
      drawingCtx.arc(renderX, renderY, radius, 0, 2 * Math.PI, false);

      var renderXextra = renderX - (BubbleObj.viewportScale.x * BUBBLE_SIZE * canvas.width * BubbleObj.objectScale * .7);
      var renderYextra = renderY - (usingYScale * BUBBLE_SIZE * canvas.height * BubbleObj.objectScale * .7);;
      
      var gradient = drawingCtx.createRadialGradient(renderXextra, renderYextra, 0, renderX, renderY, radius);
      gradient.addColorStop(0, 'rgba(0, 240, 0, 1)');
      gradient.addColorStop(.2, 'rgba(0, 180, 0, .6)');
      gradient.addColorStop(.9, 'rgba(0, 0, 0, .6)');
      gradient.addColorStop(1, 'rgba(0, 0, 0, 0)');
      
      drawingCtx.fillStyle = gradient;
      drawingCtx.fill();

      // Maybe flash.
      if (BubbleObj.flashProgress === 0 && 
          Math.random() < FLASH_PROBABILITY_PER_FRAME) {
        BubbleObj.flashProgress = 1;
      }

      if (BubbleObj.flashProgress > 0) {
        var opacity = 0;
      
        // We use an easing function that slowly lights up and then
        // produces a bright flash.
        var framesLeadup = FLASH_DURATION_FRAMES * .75;
        if (BubbleObj.flashProgress < framesLeadup) {
          opacity = .5 * BubbleObj.flashProgress / FLASH_DURATION_FRAMES;
        } else {
          opacity = Math.sin(Math.PI * (BubbleObj.flashProgress / FLASH_DURATION_FRAMES));
        }
        
        drawingCtx.globalAlpha = opacity;
        drawingCtx.beginPath();
        drawingCtx.arc(renderX, renderY, radius, 0, 2 * Math.PI, false);
        
        var gradient = drawingCtx.createRadialGradient(renderX, renderY, 0, renderX, renderY, radius);
        gradient.addColorStop(0, 'rgba(255, 255, 255, 1)');
        gradient.addColorStop(.2, 'rgba(255, 255, 255, 1)');
        gradient.addColorStop(.5, 'rgba(255, 255, 255, .6)');
        gradient.addColorStop(1, 'rgba(255, 255, 255, 0)');
        
        drawingCtx.fillStyle = gradient;
        drawingCtx.fill();
        drawingCtx.globalAlpha = 1;
        
        BubbleObj.flashProgress++;
        if (BubbleObj.flashProgress > FLASH_DURATION_FRAMES) {
          BubbleObj.flashProgress = 0;
        }
      }
 
      // Drift.
      var slowDriftWhileFlashing = 1 - (BubbleObj.flashProgress / FLASH_DURATION_FRAMES);
      BubbleObj.viewportScale.x += BUBBLE_DRIFT_RATE_PER_FRAME * BubbleObj.drift * slowDriftWhileFlashing;
      if (BubbleObj.viewportScale.x > 1) {
        BubbleObj.viewportScale.x -= 2;
      }
    }
  };
})();

(function() {
  var VERTEX_BLOCK_SIZE = 12;
  var FLASH_COUNT = 200;
  var FLASH_FRAMES_PER_MOVE = 2;
  var FLASH_DEATH_PROBABILITY_PER_FRAME = .01;

  var flashes = [];
  
  // Use a date string prefix in lieu of a random function.
  var today = new Date();
  var salt = '' + today.getYear() + today.getMonth() + today.getDate();
  
  var determineVertexDirections = function(x, y) {
    var vxstr = salt + '(' + x + ',' + y + ')';
  
    return {
      diagback: Math.abs((vxstr + 'diagback').hashCode()) % 20 === 0,
      back: Math.abs((vxstr + 'back').hashCode()) % 20 < 8,
      up: Math.abs((vxstr + 'up').hashCode()) % 20 < 8,
      diagfwd: Math.abs((vxstr + 'diagfwd').hashCode()) % 20 === 0
    };
  };
  
  var determineDirectionsFromPoint = function(x, y, lastDirection) {
    var retval = [];
    var linesFromHere = determineVertexDirections(x, y);
    if (linesFromHere.diagback) {
      retval.push({x: -VERTEX_BLOCK_SIZE, y: -VERTEX_BLOCK_SIZE});
    }
    if (linesFromHere.back) {
      retval.push({x: -VERTEX_BLOCK_SIZE, y: 0});
    }
    if (linesFromHere.up) {
      retval.push({x: 0, y: -VERTEX_BLOCK_SIZE});
    }
    if (linesFromHere.diagfwd) {
      retval.push({x: VERTEX_BLOCK_SIZE, y: -VERTEX_BLOCK_SIZE});
    }
    
    if (determineVertexDirections(x + VERTEX_BLOCK_SIZE, y).back) {
      retval.push({x: VERTEX_BLOCK_SIZE, y: 0});
    }

    if (determineVertexDirections(x - VERTEX_BLOCK_SIZE, y + VERTEX_BLOCK_SIZE).diagfwd) {
      retval.push({x: -VERTEX_BLOCK_SIZE, y: VERTEX_BLOCK_SIZE});
    }
    
    if (determineVertexDirections(x, y + VERTEX_BLOCK_SIZE).up) {
      retval.push({x: 0, y: VERTEX_BLOCK_SIZE});
    }
    
    if (determineVertexDirections(x + VERTEX_BLOCK_SIZE, y + VERTEX_BLOCK_SIZE).diagback) {
      retval.push({x: VERTEX_BLOCK_SIZE, y: VERTEX_BLOCK_SIZE});
    }

    if (lastDirection) {
      var filteredRetval = [];
      
      for (var iDir in retval) {
        var dir = retval[iDir];
        if (dir.x === lastDirection.x && dir.y === lastDirection.y) {
          return [lastDirection];
        }
        
        if (dir.x === -lastDirection.x && dir.y === -lastDirection.y) {
          // Exact opposite direction. Don't include.
          continue;
        }
        
        filteredRetval.push(dir);
      }
      
      retval = filteredRetval;
    }
    
    return retval;
  };
  
  setupCircuitGrid = function() {
    var canvas = layers.GRID_STATIC.canvas;
    var drawingCtx = layers.GRID_STATIC.drawingCtx;
    
    for (var y = 0; y < canvas.height + VERTEX_BLOCK_SIZE; y += VERTEX_BLOCK_SIZE) {
      for (var x = 0; x < canvas.width + VERTEX_BLOCK_SIZE; x += VERTEX_BLOCK_SIZE) {
        
        var lines = determineVertexDirections(x, y);
        
        var renderX = x - (VERTEX_BLOCK_SIZE / 2);
        var renderY = y - (VERTEX_BLOCK_SIZE / 2);
        
        drawingCtx.beginPath();
        
        if (lines.diagback) {
          drawingCtx.moveTo(renderX, renderY);
          drawingCtx.lineTo(renderX - VERTEX_BLOCK_SIZE, renderY - VERTEX_BLOCK_SIZE);
        }
        
        if (lines.back) {
          drawingCtx.moveTo(renderX, renderY);
          drawingCtx.lineTo(renderX - VERTEX_BLOCK_SIZE, renderY);
        }

        if (lines.up) {
          drawingCtx.moveTo(renderX, renderY);
          drawingCtx.lineTo(renderX, renderY - VERTEX_BLOCK_SIZE);
        }

        if (lines.diagfwd) {
          drawingCtx.moveTo(renderX, renderY);
          drawingCtx.lineTo(renderX + VERTEX_BLOCK_SIZE, renderY - VERTEX_BLOCK_SIZE);
        }
        
        drawingCtx.lineWidth = 2;
        drawingCtx.strokeStyle = 'rgba(0, 40, 0, 1)';
              
        drawingCtx.stroke();
      }
    }
  };
  
  animateCircuitGrid = function() {
    var canvas = layers.GRID_ANIMATED.canvas;
    var drawingCtx = layers.GRID_ANIMATED.drawingCtx;
    
    drawingCtx.clearRect(0, 0, canvas.width, canvas.height);

    for (var iFlash = 0; iFlash < FLASH_COUNT; iFlash++) {
      var flash = flashes[iFlash];
      if (!flash) {
        flash = {};
        flashes[iFlash] = flash;
      }
      
      if (!flash.position) {
        flash.position = {
          x: Math.random() * canvas.width,
          y: Math.random() * canvas.height,          
        };
        flash.position.x -= flash.position.x % VERTEX_BLOCK_SIZE;
        flash.position.y -= flash.position.y % VERTEX_BLOCK_SIZE;
      }

      if (!flash.colorPrefix) {
        var colorChooser = Math.random();
        if (colorChooser < .8) {
          flash.colorPrefix = 'rgba(120, 120, 0, ';
        } else if (colorChooser < 1) {
          flash.colorPrefix = 'rgba(255, 0, 0, ';
        } else {
          flash.colorPrefix = 'rgba(0, 255, 255, ';
        }
      }
      
      var validDirectionsFromHere =
        determineDirectionsFromPoint(flash.position.x, flash.position.y, flash.direction);
      
      if (validDirectionsFromHere.length === 0 || Math.random() < FLASH_DEATH_PROBABILITY_PER_FRAME) {
        flashes[iFlash] = null;
        continue;
      }
      
      flash.direction = 
          validDirectionsFromHere[Math.floor(Math.random() * validDirectionsFromHere.length)];
      
      if (!flash.moveProgress) {
        flash.moveProgress = 0;
      }

      var moveProgRatio = flash.moveProgress / FLASH_FRAMES_PER_MOVE;
      
      var renderX = flash.position.x + (flash.direction.x * moveProgRatio) - (VERTEX_BLOCK_SIZE / 2);
      var renderY = flash.position.y + (flash.direction.y * moveProgRatio) - (VERTEX_BLOCK_SIZE / 2);
      var radius = 10;
      
      drawingCtx.beginPath();
      drawingCtx.arc(renderX, renderY, radius, 0, 2 * Math.PI, false);

      var gradient = drawingCtx.createRadialGradient(renderX, renderY, 0, renderX, renderY, radius);
      gradient.addColorStop(0, flash.colorPrefix + '1)');
      gradient.addColorStop(.1, flash.colorPrefix + '.6)');
      gradient.addColorStop(1, 'rgba(0, 0, 0, 0)');
      
      drawingCtx.fillStyle = gradient;
      drawingCtx.fill();
      
      flash.moveProgress++;
      
      if (flash.moveProgress >= FLASH_FRAMES_PER_MOVE) {
        flash.moveProgress = 0;
        flash.position.x += flash.direction.x;
        flash.position.y += flash.direction.y;        
      }
    }
  };

})();


function onFrame(event) {
  animateCircuitGrid();
  animateBubbles();
};

///////////////////////////////////////////////////
// Put the animation into motion!

var frameTimeout = null;

var tickFrame = function() {
  onFrame();
  frameTimeout = setTimeout(tickFrame, 50);
};

$(window).resize(function() {
  for (var layerName in layers) {
    var layer = layers[layerName];
    var canvas = layer.canvas;
    
    canvas.width = window.innerWidth;
    canvas.height = window.innerHeight;
  }
  
  setupCircuitGrid();
});

///////////////////////////////////////////////////
// Doc ready.

$(document).ready(function() {
  for (var layerName in layerDepths) {
    var depth = layerDepths[layerName];
    
    canvas = document.createElement('canvas');
    drawingCtx = canvas.getContext('2d');

    layers[layerName] = {
      canvas: canvas,
      drawingCtx: drawingCtx
    };

    document.body.appendChild(canvas);

    canvas.style.background = 'transparent';
    canvas.style.left = 0;
    canvas.style.position = 'fixed';
    canvas.style.top = 0;
    canvas.style.zIndex = -9999 - depth;
  }
  
  layers.GRID_STATIC.canvas.style.background = 'black';
  layers.GRID_ANIMATED.canvas.style.opacity = .5;

  $(window).resize();  
  tickFrame();
});
