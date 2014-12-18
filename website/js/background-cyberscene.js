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
  var NUM_BUBBLES = 20;
  var BUBBLE_SIZE = .2;
  var BUBBLE_DRIFT_RATE_PER_FRAME = .0005;
  var FLASH_PROBABILITY_PER_FRAME = 0.0005;
  var FLASH_DURATION_FRAMES = 100;
  
  for (var iBubble = 0; iBubble < NUM_BUBBLES; iBubble++) {
    var BubbleObj = {};
    
    BubbleObj.viewportScale = {
      x: Math.random() * 2 - 1,
      y: Math.random() - .5
    };
    
    BubbleObj.flashProgress = 0;    
    BubbleObj.drift = Math.random();

    BubbleObj.objectScale = .5 + Math.random();
    
    Bubbles.push(BubbleObj);
  }

  animateBubbles = function() {
    var canvas = layers.BUBBLES.canvas;
    var drawingCtx = layers.BUBBLES.drawingCtx;
    
    var yScrollRatio = window.scrollY / $(document).height();
  
    drawingCtx.clearRect(0, 0, canvas.width, canvas.height);
  
    for (var iBubble = 0; iBubble < Bubbles.length; iBubble++) {
      var BubbleObj = Bubbles[iBubble];
 
      var usingYScale = BubbleObj.viewportScale.y - (yScrollRatio * .2);
 
      var renderX = (.5 + BubbleObj.viewportScale.x) * canvas.width;
      var renderY = (.5 + usingYScale) * canvas.height;

      var radiusBase = Math.min(canvas.width, canvas.height);
      var radius = radiusBase * .2 * BubbleObj.objectScale;

      drawingCtx.beginPath();
      drawingCtx.arc(renderX, renderY, radius, 0, 2 * Math.PI, false);

      var renderXextra = (.5 + BubbleObj.viewportScale.x * 1.05) * canvas.width;
      var renderYextra = (.5 + usingYScale * 1.05) * canvas.height;
      
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
      BubbleObj.viewportScale.x += BUBBLE_DRIFT_RATE_PER_FRAME * BubbleObj.drift;
      if (BubbleObj.viewportScale.x > 2) {
        BubbleObj.viewportScale.x -= 3;
      }
    }
  };
})();

(function() {
  var VERTEX_BLOCK_SIZE = 12;
  var FLASH_PROBABILITY_PER_FRAME = 0.00005;
  var FLASH_PROBABILITY_CHANGE_DIR = 0.1;

  var vertices;

  // Use a date string prefix in lieu of a random function.
  var today = new Date();
  var salt = '' + today.getYear() + today.getMonth() + today.getDate();
  
  setupCircuitGrid = function() {
    var canvas = layers.GRID_STATIC.canvas;
    var drawingCtx = layers.GRID_STATIC.drawingCtx;
    
    vertices = {};

    for (var y = 0; y < canvas.height + VERTEX_BLOCK_SIZE; y += VERTEX_BLOCK_SIZE) {
      for (var x = 0; x < canvas.width + VERTEX_BLOCK_SIZE; x += VERTEX_BLOCK_SIZE) {
        var vertexObj = {};
        
        vertexObj.position = {x: x, y: y};
        vertexObj.key = '(' + x + ',' + y + ')';
        vertices[vertexObj.key] = vertexObj;
        
        var vxstr = salt + vertexObj.key;
        
        vertexObj.lines = {
          diagback: Math.abs((vxstr + 'diagback').hashCode()) % 20 === 0,
          back: Math.abs((vxstr + 'back').hashCode()) % 20 < 8,
          up: Math.abs((vxstr + 'up').hashCode()) % 20 < 8,
          diagfwd: Math.abs((vxstr + 'diagfwd').hashCode()) % 20 === 0
        };
        
        
        vertexObj.flashing = false;
      }
    }

    for (var vxKey in vertices) {
      vertexObj = vertices[vxKey];
      
      var renderX = vertexObj.position.x - (VERTEX_BLOCK_SIZE / 2);
      var renderY = vertexObj.position.y - (VERTEX_BLOCK_SIZE / 2);
      
      drawingCtx.beginPath();
      
      if (vertexObj.lines.diagback) {
        drawingCtx.moveTo(renderX, renderY);
        drawingCtx.lineTo(renderX - VERTEX_BLOCK_SIZE, renderY - VERTEX_BLOCK_SIZE);
      }
      
      if (vertexObj.lines.back) {
        drawingCtx.moveTo(renderX, renderY);
        drawingCtx.lineTo(renderX - VERTEX_BLOCK_SIZE, renderY);
      }

      if (vertexObj.lines.up) {
        drawingCtx.moveTo(renderX, renderY);
        drawingCtx.lineTo(renderX, renderY - VERTEX_BLOCK_SIZE);
      }

      if (vertexObj.lines.diagfwd) {
        drawingCtx.moveTo(renderX, renderY);
        drawingCtx.lineTo(renderX + VERTEX_BLOCK_SIZE, renderY - VERTEX_BLOCK_SIZE);
      }
      
      drawingCtx.lineWidth = 2;
      drawingCtx.strokeStyle = 'rgba(0, 60, 0, 1)';
            
      drawingCtx.stroke();
    }
  };

})();


function onFrame(event) {
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

  $(window).resize();  
  tickFrame();
});
