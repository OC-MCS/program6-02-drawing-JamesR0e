#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	SettingsMgr * ptr;
	CircleShape bluebtn;
	CircleShape greenbtn;
	CircleShape redbtn;
	CircleShape circlebtn;
	RectangleShape rectbtn;
public:
	SettingsUI(SettingsMgr *mgr); //this constructor is initialized with data from the file through the settings manager
	void handleMouseUp(Vector2f mouse);
	void draw(RenderWindow& win);
};

