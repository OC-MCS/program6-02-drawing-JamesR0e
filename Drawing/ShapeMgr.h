#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;


//====================================================== 
// ShapeMgr: class used for storing shapes information in a vector; reading and writing the data to a binary file
//======================================================
class ShapeMgr
{
private:
	vector<DrawingShape*> drwptr;
	
public:

//====================================================== 
// default constructor: sets the drawingshapes vector to an empty set;
// parameters:  n/a
// return type: n/a
//======================================================
	ShapeMgr()
	{
		drwptr = {};
	}

//====================================================== 
// addShape: adds a drawingshape to the vector
// parameters: passed the position, type, and color of the shape
// return type: n/a
//======================================================
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

//====================================================== 
// read: reads shapes from the file and adds it to the vector
// parameters:  file
// return type: n/a
//======================================================
	void read(fstream & file)
	{
		shapedata data;
		while (file.read(reinterpret_cast<char *>(&data), sizeof(data)))
		{
			addShape(data.position, data.shape, Color(data.color));
		}
	}

//====================================================== 
// write: writes shapes from the vector to the file (calls the getFileRecord function to get a struct)
// parameters:  file
// return type: n/a
//======================================================
	void write(fstream & file)
	{
		shapedata data;
		for (int i = 0; i < drwptr.size(); i++)
		{
			data = drwptr[i]->getFileRecord();
			file.write(reinterpret_cast<char*>(&data), sizeof(data));
		}
	}

//====================================================== 
// getvector: used to access the vector
// parameters:  n/a
// return type: returns a vector to pointers to drawingShapes
//======================================================

	vector<DrawingShape*> getvector()
	{
		return drwptr;
	}

};
