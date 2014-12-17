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

var driftMists;
var scaleMists;

(function() {
  var Mists = [];
  var NUM_MISTS = 90;
  var MIST_SIZE = .2;
  var MIST_DRIFT_RATE_PER_FRAME = .0003;
  var FLASH_PROBABILITY_PER_FRAME = 0.001;
  var FLASH_DURATION_FRAMES = 100;

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

  
  var mistPath = new Path.Circle({
    center: [0, 0],
    radius: 50,
    fillColor: fillColorGreenBubble
  });
  
  var mistWhiteFlashPath = mistPath.clone();
  mistWhiteFlashPath.fillColor = fillColorWhiteFlash;
  
  var mistSymbol = new Symbol(mistPath);
  var mistFlashSymbol = new Symbol(mistWhiteFlashPath);
  
  for (var iMist = 0; iMist < NUM_MISTS; iMist++) {
    var mistObj = {};
    
    mistObj.viewportScale = Point.random();
    mistObj.viewportScale.x *= 3;
    mistObj.viewportScale.x -= 1;
    
    mistObj.instance = mistSymbol.place([0, 0]);
    mistObj.flashInstance = mistFlashSymbol.place([0, 0]);
    mistObj.flashInstance.opacity = 0;
    mistObj.flashProgress = 0;
    
    mistObj.drift = Math.random();

    mistObj.objectScale = .5 + Math.random();
    mistObj.instance.scale(mistObj.objectScale);
    mistObj.flashInstance.scale(mistObj.objectScale);
    
    Mists.push(mistObj);
  }

  driftMists = function() {
    for (var iMist = 0; iMist < Mists.length; iMist++) {
      var mistObj = Mists[iMist];
      mistObj.instance.position = mistObj.viewportScale * view.size;
      mistObj.flashInstance.position = mistObj.viewportScale * view.size;
 
      // Drift.
      mistObj.viewportScale.x += MIST_DRIFT_RATE_PER_FRAME * mistObj.drift;
      if (mistObj.viewportScale.x > 2) {
        mistObj.viewportScale.x -= 3;
      }
      
      // Maybe flash.
      if (mistObj.flashProgress === 0 && 
          Math.random() < FLASH_PROBABILITY_PER_FRAME) {
        mistObj.flashProgress = 1;
      }
      
      if (mistObj.flashProgress > 0) {
        
      }
    }
  };
  
  var currentSizeScale = 100;
  
  scaleMists = function() {
    var newSizeScale = MIST_SIZE * Math.max(view.size.width, view.size.height);
  
    for (var iMist = 0; iMist < Mists.length; iMist++) {
      var mistObj = Mists[iMist];
      
      mistObj.instance.scale(newSizeScale / currentSizeScale);
      mistObj.flashInstance.scale(newSizeScale / currentSizeScale);
    }
    
    currentSizeScale = newSizeScale;
  };
})();

function onResize(event) {
  scaleMists();
}

function onFrame(event) {
  driftMists();
};
