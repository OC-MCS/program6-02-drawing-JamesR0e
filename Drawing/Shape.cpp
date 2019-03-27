#include <iostream>
#include "Shape.h"

Circle::Circle(Color color, Vector2f position)
{
	c.setPosition(position);
	c.setFillColor(color);
}
void Circle::draw(RenderWindow win)
{
	win.draw(c);
}
shapedata Circle::getFileRecord()
{
	shapedata circle;
	circle.color = c.getFillColor();
	circle.position = c.getPosition();
	return circle;
}

Square::Square(Color color, Vector2f position)
{
	s.setPosition(position);
	s.setFillColor(color);
}
void Square::draw(RenderWindow win)
{
	win.draw(s);
}
shapedata Square::getFileRecord()
{
	shapedata square;
	square.color = s.getFillColor();
	square.position = s.getPosition();
	return square;
}