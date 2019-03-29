#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"


//class drawing UI draws the shapes and the canvas to the frame; also determines if mouse in on canvas
class DrawingUI
{
private:
	RectangleShape r;
public:

//====================================================== 
// constructor: sets the position of the canvas
// parameters: position of canvas (Vector2f)
// return type: n/a
//======================================================
	DrawingUI(Vector2f p)
	{
		r.setPosition(p);
	}

//====================================================== 
// draw: draws the canvas and all the shapes on it each frame
// parameters:  window and ptr to the shapesMgr
// return type: n/a
//======================================================
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		//canvas
		r.setOutlineThickness(4);
		r.setOutlineColor(Color::White);
		r.setSize(Vector2f(615, 550));
		r.setFillColor(Color::Transparent);
		win.draw(r);

		//drawingshapes
		vector<DrawingShape*> ptr;
		ptr = mgr->getvector();
		for (int i = 0; i < ptr.size(); i++)
		{
			ptr[i]->draw(win);
		}

	}
	
//====================================================== 
// isMouseInCanvas: determines if the mouse is on the canvas
// parameters:  mouse position
// return type: returns a bool
//======================================================
	bool isMouseInCanvas(Vector2f mousePos)
	{
		bool valid = true;
		if (!r.getGlobalBounds().contains(mousePos))
		{
			valid = false;
		}
		return valid;
	}

};

