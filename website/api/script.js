// Enhanced functionality for full-text reading.
// Dopamine
// Copyright (c) 2015 Mikhail Voloshin
// All rights reserved.
// http://dopaminenovel.com/


var hasAlphanumerics = function(s) {
  return !!s.match(/[a-zA-Z0-9]/);
}

$(document).ready(function() {
  var paragraphs = $('p, pre, div.email, div.message');
  var totalwordcount = 0;

  for (var iparagraph = 0; iparagraph < paragraphs.length; iparagraph++) {
    var paragraph = $(paragraphs[iparagraph]);
    paragraph.attr('data-paragraph-number', iparagraph);
    
    var text = paragraph.text();
    var words = text.split(/[ ,\-\>]+/);
    var wc = 0;
    for (var iword = 0; iword < words.length; iword++) {
      var word = words[iword];
      if (!hasAlphanumerics(word)) {
        continue;
      }
      
      wc++;
    }
    
    paragraph.attr('data-paragraph-wordcount', wc);
    totalwordcount += wc;
  }

  console.log('Word count: ' + totalwordcount);

  
  var findTopParagraph = function() {
    var windowScrollPos = $(window).scrollTop();

    for (var iparagraph = 0; iparagraph < paragraphs.length; iparagraph++) {
      var pgtop = $(paragraphs[iparagraph]).offset().top;
      if (pgtop > windowScrollPos) {
        return iparagraph;
      }
    }
    return 0;
  };


  var parseHash = function() {
    var retval = {};
    var ands = location.hash.substring(1).split('&');
    for (var iand = 0; iand < ands.length; iand++) {
      var nameval = ands[iand].split('=');
      retval[nameval[0]] = nameval[1] || 'true';
    }
    return retval;
  };
  

  var isUpdating = false;
  var markUpdating = function() {
    isUpdating = true;
    setTimeout(function() { isUpdating = false; }, 100);
  };

  
  var setHashToCurrentTopParagraph = function() {
    if (isUpdating) {
      return;
    }
    markUpdating();

    var iparagraph = findTopParagraph();
    location.hash = 'p=' + iparagraph;
  };
  
  var scrollToParagraph = function(iparagraph) {
    var paragraph = $('[data-paragraph-number=' + iparagraph + ']');
    var pgtop = paragraph.offset().top;
    $(window).scrollTop(pgtop);
  };

  var highlightParagraphs = function(iparagraph, numWordsToHighlight) {
    $('.highlighted').removeClass('highlighted');

    var numWordsHighlighted = 0;
    while (numWordsHighlighted < numWordsToHighlight) {
      var paragraph = $('[data-paragraph-number=' + iparagraph + ']');
      
      paragraph.addClass('highlighted');
      paragraph.parents().addClass('highlighted');
      
      numWordsHighlighted += parseInt(paragraph.attr('data-paragraph-wordcount'));
      
      iparagraph++;
    }
    
    $('*').css('display', 'none');
    $('.highlighted, .highlighted br').css('display', '');
    $(window).scrollTop(0);
  }
  
  var updateScroll = function() {
    if (isUpdating) {
      return;
    }
    markUpdating();
    
    var hashparams = parseHash();
    if ('p' in hashparams) {
      var iparagraph = parseInt(hashparams.p);
      scrollToParagraph(iparagraph);
      
      if ('h' in hashparams) {
        var numWordsToHighlight = parseInt(hashparams.h);
        highlightParagraphs(iparagraph, numWordsToHighlight);
      }
    }
  };
  
  $(window).scroll(function() {
    setHashToCurrentTopParagraph();
  });

  $(window).on('hashchange', function(){
    updateScroll();
  });
  
  updateScroll();
});


