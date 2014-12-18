// The following is a PaperScript script, which is not real JavaScript.
// It uses PaperJS to animate the giant background canvas.

// 3D grid:
// The viewer's eye is (0, 0, 0).
// The center of the screen is (0, 0, SCREEN_Z).
// X coordinate increases to the right.
// Y coordinate increases upward.
// Z coordinate increases into the screen, away from the viewer.

// The Z coordinate of the pane of the screen.
var SCREEN_Z = 4096;

var canvas;
var drawingCtx;

var drawBubbles;

(function() {
  var Bubbles = [];
  var NUM_BUBBLES = 40;
  var BUBBLE_SIZE = .2;
  var BUBBLE_DRIFT_RATE_PER_FRAME = .0003;
  var FLASH_PROBABILITY_PER_FRAME = 0.0005;
  var FLASH_DURATION_FRAMES = 100;

  /*
  
  var transgreen = new Color(0, .6, 0, .4);
  var transparent = new Color(0, 0, 0, 0);

  var fillColorGreenBubble = {
    gradient: {
      stops: [['green', 0], [transgreen, .2], [transgreen, .3], ['black', .9], [transparent, 1]],
      radial: true
    },
    origin: [0, 0],
    destination: [50, 0]
  };

  var fillColorWhiteFlash = {
    gradient: {
      stops: [['white', 0], ['white', .4], [transparent, 1]],
      radial: true
    },
    origin: [0, 0],
    destination: [50, 0]
  };

  
  var BubblePath = new Path.Circle({
    center: [0, 0],
    radius: 50,
    fillColor: fillColorGreenBubble
  });
  
  var BubbleWhiteFlashPath = BubblePath.clone();
  BubbleWhiteFlashPath.fillColor = fillColorWhiteFlash;
  
  var BubbleSymbol = new Symbol(BubblePath);
  var BubbleFlashSymbol = new Symbol(BubbleWhiteFlashPath);
  
  */
  
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

  drawBubbles = function() {
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
      gradient.addColorStop(0, 'rgba(0, 150, 0, 1)');
      gradient.addColorStop(.2, 'rgba(0, 120, 0, .6)');
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

  //var transgreen = new Color(0, .6, 0, .4);
  //var transparent = new Color(0, 0, 0, 0);

  //var fillColorGreenBubble = {
    //gradient: {
      //stops: [['green', 0], [transgreen, .2], [transgreen, .3], ['black', .9], [transparent, 1]],
      
      
 
      // Drift.
      BubbleObj.viewportScale.x += BUBBLE_DRIFT_RATE_PER_FRAME * BubbleObj.drift;
      if (BubbleObj.viewportScale.x > 2) {
        BubbleObj.viewportScale.x -= 3;
      }
    }
  };
})();

var drawGrid;

(function() {
  var NUM_X = 80;
  var NUM_Y = 60;
  var FLASH_PROBABILITY_PER_FRAME = 0.00005;
  var FLASH_PROBABILITY_CHANGE_DIR = 0.1;

  var vertices = {};
  
  for (var y = 0; y < NUM_Y; y++) {
    for (var x = 0; x < NUM_X; x++) {
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
  
  var drawNum = 0;
  
  drawGrid = function() {
    for (var vxKey in vertices) {
      vertexObj = vertices[vxKey];
      
      var renderDX = canvas.width / (NUM_X - 1);      
      var renderDY = canvas.height / (NUM_Y - 1);
      var renderX = renderDX * vertexObj.position.x;
      var renderY = renderDY * vertexObj.position.y;
      
      if (!vertexObj.flashing) {
        if (Math.random() < FLASH_PROBABILITY_PER_FRAME) {
          vertexObj.flashing = true;
          vertexObj.flashDirection = Math.floor(Math.random() * 4);
          vertexObj.flashDrawNum = 0;
        }
      }
      
      drawingCtx.beginPath();
      
      if (vertexObj.lines.diagback) {
        drawingCtx.moveTo(renderX, renderY);
        drawingCtx.lineTo(renderX - renderDX, renderY - renderDY);
      }
      
      if (vertexObj.lines.back) {
        drawingCtx.moveTo(renderX, renderY);
        drawingCtx.lineTo(renderX - renderDX, renderY);
      }

      if (vertexObj.lines.up) {
        drawingCtx.moveTo(renderX, renderY);
        drawingCtx.lineTo(renderX, renderY - renderDY);
      }

      if (vertexObj.lines.diagfwd) {
        drawingCtx.moveTo(renderX, renderY);
        drawingCtx.lineTo(renderX + renderDX, renderY - renderDY);
      }
      
      if (vertexObj.flashing) {
        drawingCtx.lineWidth = 3;
        drawingCtx.strokeStyle = 'rgba(20, 40, 0, 1)';      
      } else {
        drawingCtx.lineWidth = 2;
        drawingCtx.strokeStyle = 'rgba(0, 20, 0, 1)';
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
      
      drawingCtx.stroke();
    }
    
    drawNum++;
  };

})();


function onFrame(event) {
  drawGrid();
  drawBubbles();
};

///////////////////////////////////////////////////
// Put the animation into motion!

var frameTimeout = null;

var tickFrame = function() {
  canvas.width = window.innerWidth;
  canvas.height = window.innerHeight;
  
  drawingCtx.clearRect(0, 0, canvas.width, canvas.height);

  onFrame();
  frameTimeout = setTimeout(tickFrame, 50);
};

///////////////////////////////////////////////////
// Doc ready.

$(document).ready(function() {
  canvas = document.getElementById('cyberscene');
  drawingCtx = canvas.getContext('2d');
  
  tickFrame();
});
