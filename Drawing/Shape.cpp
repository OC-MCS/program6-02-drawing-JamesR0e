#include <iostream>
#include "Shape.h"

Circle::Circle(Color color, Vector2f position)
{
	c.setPosition(position);
	c.setFillColor(color);
}
void Circle::draw(RenderWindow & win)
{
	c.setRadius(10);
	win.draw(c);
}
shapedata Circle::getFileRecord()
{
	shapedata circle;
	circle.color = c.getFillColor().toInteger();
	circle.position = c.getPosition();
	circle.shape = CIRCLE;
	return circle;
}

Square::Square(Color color, Vector2f position)
{
	s.setPosition(position);
	s.setFillColor(color);
}
void Square::draw(RenderWindow & win)
{
	s.setSize(Vector2f(15, 15));
	win.draw(s);
}
shapedata Square::getFileRecord()
{
	shapedata square;
	square.color = s.getFillColor().toInteger();
	square.position = s.getPosition();
	square.shape = SQUARE;
	return square;
}
