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
	void read(fstream & file)
	{
		shapedata data;
		while (file.read(reinterpret_cast<char *>(&data), sizeof(data)))
		{
			addShape(data.position, data.shape, Color(data.color));
		}
	}
	void write(fstream & file)
	{
		shapedata data;
		for (int i = 0; i < drwptr.size(); i++)
		{
			data = drwptr[i]->getFileRecord();
			file.write(reinterpret_cast<char*>(&data), sizeof(data));
		}
	}

	vector<DrawingShape*> getvector()
	{
		return drwptr;
	}

};
