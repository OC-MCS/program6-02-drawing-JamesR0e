#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
struct shapedata
{
	Color color;
	Vector2f position;
};
class DrawingShape 
{
public:
	virtual void draw(RenderWindow & win) = 0;
	virtual shapedata getFileRecord() = 0;
};

// add Circle, Square classes below. These are derived from DrawingShape

class Circle : public DrawingShape
{
private:
	CircleShape c;
public:
	Circle(Color color, Vector2f position);
	void draw(RenderWindow & win);
	shapedata getFileRecord();
};

class Square : public DrawingShape
{
private:
	RectangleShape s;
public:
	Square(Color color, Vector2f position);
	void draw(RenderWindow & win);
	shapedata getFileRecord();
	
};



