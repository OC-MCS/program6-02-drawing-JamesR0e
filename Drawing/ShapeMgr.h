#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> drwptr;
	
public:
	ShapeMgr()
	{
		drwptr = {};
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			drwptr.push_back(new Circle(color, pos));
		}
		else if (whichShape == SQUARE)
		{
			drwptr.push_back(new Square(color, pos));
		}

	}

	vector<DrawingShape*> getvector()
	{
		return drwptr;
	}

};
