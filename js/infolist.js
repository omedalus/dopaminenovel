$(document).ready(function() {
  $('body').on('click', 'a.infolistitem-header', function() {
    var jqHeadLink = $(this),
        jqInfoList = jqHeadLink.parents('.infolist'),
        jqCorrespondingContent = jqHeadLink.next(),
        jqCorrespondingCollapsed =
            jqCorrespondingContent.children('.infolistitem-collapsed');

    var wasOpen = jqHeadLink.hasClass('active');

    // Clean up previous opened stuff.
    jqInfoList.find('a.infolistitem-header').removeClass('active');
    jqInfoList.find('.infolistitem-content').
        css('height', '').
        css('opacity', '');

    if (!wasOpen) {
      // Open us.
      jqHeadLink.addClass('active');
      jqCorrespondingContent.height(jqCorrespondingCollapsed.height()).
          css('opacity', '1');
    }
  });
});
