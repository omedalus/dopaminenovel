// Listing results of Mechanical Turk alongside text.
// Dopamine
// Copyright (c) 2015 Mikhail Voloshin
// All rights reserved.
// http://dopaminenovel.com/


var pidToLoad = 0;

var loadNextMturkFeedback = function(pid) { pidToLoad = pid; };

$(document).ready(function() {
  $('body').css('margin-right', '360px');
  
  var mturkFloater = 
      $('<div id="mturk"><h1>Mechanical Turk feedback</h1>' + 
        '<h2>Position: <span id="mturk-position"></span> ' +
        '(next: <span id="mturk-position-next"></span>)</h2>' + 
        '<div id="mturk-content"></div></div>').
        appendTo('body').
        css({
          'background': '#cfc',
          'border': '1px solid #0c0',
          'border-radius': '5px',
          'box-sizing': 'border-box',
          'color': '#060',
          'font-size': '10px',
          'right': '10px',
          'padding': '10px',
          'position': 'fixed',
          'top': '10px',
          'width': '320px',
        });
  
  $('h1', mturkFloater).css({
    'margin': '0'
  });
  $('h2', mturkFloater).css({
    'margin': '0'
  });

  var mturkPosition = $('#mturk-position', mturkFloater);
  var mturkPositionNext = $('#mturk-position-next', mturkFloater);
  var mturkContent = $('#mturk-content', mturkFloater).css({
    'margin-top': '10px'
  });

  var mturkAjaxLoad = $.ajax('api/get_mturk_edits.php').
      done(function(mturkData) {
        loadNextMturkFeedback = function(pid) {
          var i = 0;
          for (; i < mturkData.length; i++) {
            if (mturkData[i].p >= pid) {
              break;
            }
          }

          if (i >= mturkData.length) {
            return;
          }

          var firstItemAbovePid = mturkData[i];
          var nextpid = null;
          if (i < mturkData.length - 1) {
            nextpid = mturkData[i + 1].p;
            mturkPositionNext.text(nextpid);
          }
          
          if (firstItemAbovePid !== null) {
            mturkPosition.text(firstItemAbovePid.p);
            
            var sugtext = $('<div/>').text(firstItemAbovePid.suggestion).
                html().
                replace(/\n/g, "<br/>");
            mturkContent.html(sugtext);
          }
        };
        
        loadNextMturkFeedback(pidToLoad);
      }).
      error(function() {
        console.log('ERROR: Could not load Mechanical Turk feedback.');
      });
});



