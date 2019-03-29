#include <iostream>
#include "Shape.h"

//====================================================== 
// circle constructor: sets the position and color
// parameters: color and position
// return type: n/a
//====================================================== 
Circle::Circle(Color color, Vector2f position)
{
	c.setPosition(position);
	c.setFillColor(color);
}

//====================================================== 
// draw: gives the circle a radius then draws it
// parameters: window
// return type: n/a
//====================================================== 
void Circle::draw(RenderWindow & win)
{
	c.setRadius(10);
	win.draw(c);
}

//====================================================== 
// getfilerecord: used in reading and writing to the file; puts circleinfo into a struct
// parameters:  n/a
// return type: returns a struct with circle data
//====================================================== 
shapedata Circle::getFileRecord()
{
	shapedata circle;
	circle.color = c.getFillColor().toInteger();
	circle.position = c.getPosition();
	circle.shape = CIRCLE;
	return circle;
}

//====================================================== 
// square constructor: sets the position and color
// parameters: color and position
// return type: n/a
//====================================================== 
Square::Square(Color color, Vector2f position)
{
	s.setPosition(position);
	s.setFillColor(color);
}

//====================================================== 
// draw: gives the square a size then draws it
// parameters: window
// return type: n/a
//====================================================== 
void Square::draw(RenderWindow & win)
{
	s.setSize(Vector2f(15, 15));
	win.draw(s);
}

//====================================================== 
// getfilerecord: used in reading and writing to the file; puts squareinfo into a struct
// parameters:  n/a
// return type: returns a struct with square data
//======================================================
shapedata Square::getFileRecord()
{
	shapedata square;
	square.color = s.getFillColor().toInteger();
	square.position = s.getPosition();
	square.shape = SQUARE;
	return square;
}
