#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	RectangleShape r;
public:
	DrawingUI(Vector2f p)
	{
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		Vector2f pos(150, 25);
		r.setPosition(pos);
		r.setOutlineThickness(4);
		r.setOutlineColor(Color::White);
		r.setSize(Vector2f(600, 550));
		r.setFillColor(Color::Transparent);
		win.draw(r);
	}
	
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

