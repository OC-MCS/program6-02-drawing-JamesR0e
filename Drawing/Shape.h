#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "SettingsMgr.h"

using namespace std;
using namespace sf;


//struct used for writing data to and from binary file
struct shapedata
{
	ShapeEnum shape;
	int color;
	Vector2f position;
};

//abstract base class for shapes
class DrawingShape 
{
public:
	virtual void draw(RenderWindow & win) = 0;
	virtual shapedata getFileRecord() = 0;
};

//class circle is derived from DrawingShape
class Circle : public DrawingShape
{
private:
	CircleShape c;
public:
	Circle(Color color, Vector2f position);
	void draw(RenderWindow & win);
	shapedata getFileRecord();
};

//class square is derived from DrawingShape
class Square : public DrawingShape
{
private:
	RectangleShape s;
public:
	Square(Color color, Vector2f position);
	void draw(RenderWindow & win);
	shapedata getFileRecord();
	
};



