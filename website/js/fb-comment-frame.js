fbCommentFrameApp = angular.module('fbcommentframe', []);

fbCommentFrameApp.controller('FbCommentFrameController', ['$scope',
  function($scope) {
  
  $scope.getCommentUrl = function() {
    return unescape($.url().param('url'));
  };
}]);