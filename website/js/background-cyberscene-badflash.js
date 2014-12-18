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
  
    drawingCtx.clearRect(0, 0, canvas.width, canvas.height);
  
    for (var iBubble = 0; iBubble < Bubbles.length; iBubble++) {
      var BubbleObj = Bubbles[iBubble];
 
      var renderX = (.5 + BubbleObj.viewportScale.x) * canvas.width;
      var renderY = (.5 + BubbleObj.viewportScale.y) * canvas.height;

      var radiusBase = Math.min(canvas.width, canvas.height);
      var radius = radiusBase * .2 * BubbleObj.objectScale;

      drawingCtx.beginPath();
      drawingCtx.arc(renderX, renderY, radius, 0, 2 * Math.PI, false);

      var renderXextra = (.5 + BubbleObj.viewportScale.x * 1.05) * canvas.width;
      var renderYextra = (.5 + BubbleObj.viewportScale.y * 1.05) * canvas.height;
      
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
  var VERTEX_BLOCK_SIZE = 32;
  var FLASH_PROBABILITY_PER_FRAME = 0.00005;
  var FLASH_PROBABILITY_CHANGE_DIR = 0.1;

  var vertices;
    
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
        
        vertexObj.lines = {
          diagback: Math.random() < .05,
          back: Math.random() < .4,
          up: Math.random() < .4,
          diagfwd: Math.random() < .05
        };
        
        vertexObj.flashing = false;
      }
    }

    for (var vxKey in vertices) {
      vertexObj = vertices[vxKey];
      
      var renderX = VERTEX_BLOCK_SIZE * vertexObj.position.x - (VERTEX_BLOCK_SIZE / 2);
      var renderY = VERTEX_BLOCK_SIZE * vertexObj.position.y - (VERTEX_BLOCK_SIZE / 2);
      drawingCtxGrid.beginPath();
      
      if (vertexObj.lines.diagback) {
        drawingCtxGrid.moveTo(renderX, renderY);
        drawingCtxGrid.lineTo(renderX - renderDX, renderY - renderDY);
      }
      
      if (vertexObj.lines.back) {
        drawingCtxGrid.moveTo(renderX, renderY);
        drawingCtxGrid.lineTo(renderX - renderDX, renderY);
      }

      if (vertexObj.lines.up) {
        drawingCtxGrid.moveTo(renderX, renderY);
        drawingCtxGrid.lineTo(renderX, renderY - renderDY);
      }

      if (vertexObj.lines.diagfwd) {
        drawingCtxGrid.moveTo(renderX, renderY);
        drawingCtxGrid.lineTo(renderX + renderDX, renderY - renderDY);
      }
      
      if (vertexObj.flashing) {
        drawingCtxGrid.lineWidth = 3;
        drawingCtxGrid.strokeStyle = 'rgba(20, 60, 0, 1)';      
      } else {
        drawingCtxGrid.lineWidth = 2;
        drawingCtxGrid.strokeStyle = 'rgba(0, 20, 0, 1)';
      }
      
      if (vertexObj.flashing && vertexObj.flashDrawNum !== drawNum) {
        var nextFlashDir = vertexObj.flashDirection;
        
        if (Math.random() < FLASH_PROBABILITY_CHANGE_DIR) {
          nextFlashDir = Math.floor(Math.random() * 4);
        }
        
        var nextFlashX = vertexObj.position.x;
        var nextFlashY = vertexObj.position.y;
        
        if (nextFlashDir === 0) {
          nextFlashX--;
        } else if (nextFlashDir === 1) {
          nextFlashX++;        
        } else if (nextFlashDir === 2) {
          nextFlashY--;
        } else if (nextFlashDir === 3) {
          nextFlashY++;
        }

        var nextVertexObjFlash = vertices['(' + nextFlashX + ',' + nextFlashY + ')'];
        if (nextVertexObjFlash) {
          nextVertexObjFlash.flashing = true;
          nextVertexObjFlash.flashDirection = nextFlashDir;
          nextVertexObjFlash.flashDrawNum = drawNum;
        }
      }
      
      if (vertexObj.flashDrawNum != drawNum) {
        vertexObj.flashing = false;
      }
      
      drawingCtxGrid.stroke();
    }
    
    drawNum++;
  };

})();


function onFrame(event) {

  //setupCircuitGrid();
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

    canvas.style.background = 'black';
    canvas.style.left = 0;
    canvas.style.position = 'fixed';
    canvas.style.top = 0;
    canvas.style.zIndex = -9999 - depth;
  }

  $(window).resize();  
  tickFrame();
});
