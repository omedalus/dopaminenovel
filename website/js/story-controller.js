dopamineNovelApp.controller('StoryController', ['$location', '$scope',
  '$rootScope', '$routeParams', 'ChapterResource', 
  function($location, $scope, $rootScope, $routeParams, ChapterResource) {
    var chapterListPromise = ChapterResource.list();
    var chapterActsPromise = ChapterResource.acts();
    
    $scope.chapterList = [];
    $scope.chapterActs = {};
    
    chapterListPromise.success(function(data) {
      $scope.chapterList = data;
    });

    chapterActsPromise.success(function(data) {
      $scope.chapterActs = data;
    });

    var chapterShift = function(shift) {
      if (!angular.isDefined($rootScope.chapter) ||
          $rootScope.chapter == null ||
          !$scope.chapterList ||
          !$scope.chapterList.length) {
        return null;
      }
      
      var indexDesired =
          $scope.chapterList.indexOf($rootScope.chapter) + shift;
      
      if (indexDesired < 0 || 
          indexDesired >= $scope.chapterList.length) {
        return null;
      }
      return $scope.chapterList[indexDesired];
    }
      
    $scope.previousChapter = function() {
      return chapterShift(-1);
    };
    
    $scope.nextChapter = function() {
      return chapterShift(1);
    };

    $scope.fbCommentFrameHref = function() {
      return $location.absUrl();
    }

    $scope.fbApply = function() {
      if (typeof FB !== 'undefined' && FB && FB.XFBML) {
        FB.XFBML.parse();
      }
    }

    $scope.$watch(function() {
      return (!angular.isDefined($routeParams.chapter) || 
          $routeParams.chapter == null) ? null :
              parseInt($routeParams.chapter, 10);
    }, function(newValue, oldValue) {
      var isStorymode = newValue !== null;

      $rootScope.chapter = newValue;
      $rootScope.storymode = isStorymode;

      $scope.fbApply();
      
      $scope.chapterContents = null;
      if (newValue) {
        ChapterResource.get(newValue).success(function(data) {
          $scope.chapterContents = JSON.parse(data);
        });
      }
    });
  }
]);
