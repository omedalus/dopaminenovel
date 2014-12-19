$(document).ready(function() {
  window.name = 'dopaminenovelwindow';
});

dopamineNovelApp = angular.module('dopaminenovel', ['ngResource', 'ngSanitize']);

dopamineNovelApp.
    config(['$routeProvider', function($routeProvider) {
      $routeProvider.
          when('/story', {
            templateUrl: 'views/story.html'
          }).
          when('/author', {
            templateUrl: 'views/author.html'
          }).
          when('/hacking', {
            templateUrl: 'views/hacking.html'
          }).
          when('/biotech', {
            templateUrl: 'views/biotech.html'
          }).
          when('/friends', {
            templateUrl: 'views/friends.html'
          }).
          otherwise({
            redirectTo: '/story'
          });
    }]).
    directive('dnNav', ['$location', function($location) {
      return {
        scope: {},
        link: function(scope, iElement, iAttrs) {
          scope.getCurrentNavpoint = function() {
            return $location.path().substr(1);
          };
        
          var listItems = iElement.find('li'),
              liByPoint = {};
              
          listItems.each(function() {
            var jqLi = $(this),
                href = jqLi.data('dnNavHref');
            $('<a/>').attr('href', '#/' + href).
                append(jqLi.contents()).
                appendTo(jqLi);
            
            liByPoint[href] = jqLi;
          });
          
          scope.$watch('getCurrentNavpoint()', function(newPoint) {
            listItems.find('a').removeClass('active');
            $(liByPoint[newPoint]).find('a').addClass('active');
          });
        }
      };
    }]).
    run(['$rootScope', '$timeout', function($rootScope, $timeout) {
      $rootScope.$on('$locationChangeSuccess', function(ev) {
        if (typeof FB !== 'undefined' && FB && FB.XFBML) {
          // Refresh all Facebook widgets after the DOM is done.
          $timeout(function() {
            FB.XFBML.parse();
            console.log('refreshed');
          });
        }
      });
    }]);

