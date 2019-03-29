#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"


//the purpose of this class is to provide the userinterface for the settings and handle userinput on the settings
class SettingsUI
{
private:
	//ptr to the settingsmanager (used for determining button settings)
	SettingsMgr * ptr;

	//button information
	CircleShape bluebtn; 
	CircleShape greenbtn;
	CircleShape redbtn;
	CircleShape circlebtn;
	RectangleShape rectbtn;
public:
	SettingsUI(SettingsMgr *mgr); //this constructor is initialized with data from the file through the settings manager
	void handleMouseUp(Vector2f mouse);  //handles mouse input for buttons
	void draw(RenderWindow& win); //creates and draws the settings to the frame
};

