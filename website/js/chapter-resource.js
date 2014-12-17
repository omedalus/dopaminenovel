dopamineNovelApp.factory('ChapterResource', ['$http', function($http) {
  return {
    list: function() {
      return $http.get('/api/list_chapters.php');
    },

    acts: function() {
      return $http.get('/api/list_acts.php');
    },
    
    get: function(chapternum) {
      chapternum = parseInt('' + chapternum, 10);
      if (chapternum > 999) {
        return;
      }
    
      return $http.get('/api/chapter.php?chapternum=' + chapternum);
    }
  };
}]);
