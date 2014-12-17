// The following is a PaperScript script, which is not real JavaScript.
// It uses PaperJS to animate the giant background canvas.

// 3D grid:
// The viewer's eye is (0,0,0).
// X coordinate increases to the right.
// Y coordinate increases upward.
// Z coordinate increases into the screen, away from the viewer.

// The Z coordinate of the pane of the screen.
var SCREEN_Z = 4096;

// The number of pixels apart that the grid floor lines are arranged at,
// at the Z intercept.
var GRID_FLOOR_LINE_SPACING = 256;

// The number of screen depths away that the horizon is.
var GRID_HORIZON_SCREEN_DEPTHS = 10;

var drawGridFloor = new function() {
  var numGridLines = 10;
  
  for (var iLine = 0; iLine < numGridLines; iLine++) {
    Path.Circle({
      center: [iLine * 10, iLine * 10],
      radius: 10,
      fillColor: 'green'
    });
  }
};

function onFrame(event) {
  drawGridFloor();
};