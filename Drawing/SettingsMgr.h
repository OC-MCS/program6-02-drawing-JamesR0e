#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

//the purpose of this class is to keep up with the settings information and read and write this info from the file
class SettingsMgr
{
private:
	Color currentColor;
	ShapeEnum currentShape;

public:

//====================================================== 
// constructor: sets the default settings for intial program run
// parameters:  n/a
// return type: n/a
//======================================================
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		currentColor = startingColor;
		currentShape = startingShape;
	}

//====================================================== 
// getCurColor: returns the current Color setting
// parameters:  n/a
// return type: returns a Color
//======================================================
	Color getCurColor()
	{
		return currentColor;
	}

//====================================================== 
// getCurShape: returns the current Shape setting
// parameters:  n/a
// return type: returns a shapeEnum
//======================================================
	ShapeEnum getCurShape()
	{
		return currentShape;
	}

//====================================================== 
// setcurrentColor: currentColor manipulator
// parameters:  Color
// return type: n/a
//======================================================
	void setcurrentColor(Color c)
	{
		currentColor = c;
	}

//====================================================== 
// setcurrentShape: currentShape manipulator
// parameters:  ShapeEnum
// return type: n/a
//======================================================
	void setcurrentShape(ShapeEnum s)
	{
		currentShape = s;
	}

//====================================================== 
// read: reads the currentsettings from the binary file; converts color int to a color
// parameters:  file
// return type: n/a
//======================================================
	void read(fstream & file)
	{
		int color;
		ShapeEnum Currentshape;
		file.read(reinterpret_cast<char *>(&color), sizeof(color));
		file.read(reinterpret_cast<char *>(&Currentshape), sizeof(Currentshape));
		currentColor = Color(color); //converts color number back into a color
		currentShape = Currentshape;
	}

//====================================================== 
// write: writes the settings information to the binary file; converts the color to an int
// parameters:  file
// return type: n/a
//======================================================
	void write(fstream & file)
	{
		int color;
		color = currentColor.toInteger(); //converts color to an int
		file.write(reinterpret_cast<char *>(&color), sizeof(color));
		file.write(reinterpret_cast<char *>(&currentShape), sizeof(currentShape));
	}

};
