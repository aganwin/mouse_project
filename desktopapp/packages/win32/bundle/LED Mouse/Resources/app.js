/**
* Copyright (c) 2012 Software in the Public Interest (SPI) Inc.
* Copyright (c) 2012 David Pratt
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*	http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/

// create and set menu
/*var menu = Ti.UI.createMenu(),
fileItem = Ti.UI.createMenuItem('File'),
exitItem = fileItem.addItem('Exit', function() {
  if (confirm('Are you sure? Notification feature will not work if you quit the app.')) {
    Ti.App.exit();
  }
});

menu.appendItem(fileItem);
Ti.UI.setMenu(menu);*/



$(document).ready(function() {
   // $("#home-view").hide();
   // $("#facebook-view").show();
   
//------------------Exit Button--------------------------------
  $(".icon-remove-circle").hover(function() {      //move in
    $(this).animate({
      fontSize: 19,
      },{
      duration: 100
      });
    },function(){
    $(this).animate({fontSize: 15});              //move out
  }); 
  
  $(".icon-remove-circle").click(function() {     //onlcick 
    Ti.App.exit();
  });
  
//-----------Nav Bar View Controller---------------------------
  $("#home-icon").click(function() {
    $("#fb-icon, #gm-icon, #st-icon").removeClass("active");
    $(this).addClass("active");
    $("#home-view").show();
    $("#facebook-view, #gmail-view, #setting-view").hide();
  });
  $("#fb-icon").click(function() {
    $("#home-icon, #st-icon, #gm-icon").removeClass("active");
    $(this).addClass("active");
    $("#facebook-view").show();
    $("#home-view, #gmail-view, #setting-view").hide();
  });
  $("#gm-icon").click(function() {
    $("#home-icon, #fb-icon, #st-icon").removeClass("active");
    $(this).addClass("active");
    $("#gmail-view").show();
    $("#facebook-view, #home-view, #setting-view").hide();
  });
  $("#st-icon").click(function() {
    $("#home-icon, #fb-icon, #gm-icon").removeClass("active");
    $(this).addClass("active");
    $("#setting-view").show();
    $("#home-view, #facebook-view, #gmail-view").hide();
  });
  

  //<button style="position: absolute; left:+44%; top: 80%" class="btn btn-primary" id="fb-login-button"><img src="@routes.Assets.at("/public", "img/fb_icon_orange.png")"> Login </button>
   
  $("li").hover(function(){
    $(this).css({'font-weight' : 'bolder'});
    }, function () {
    var cssObj = {
      'font-weight' : ''
    };
    $(this).css(cssObj);
  });

 });