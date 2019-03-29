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
		p.x = 0;
		p.y = 0;
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		Vector2f pos(150, 25);
		r.setPosition(pos);
		r.setOutlineThickness(4);
		r.setOutlineColor(Color::White);
		r.setSize(Vector2f(615, 550));
		r.setFillColor(Color::Transparent);
		win.draw(r);

		vector<DrawingShape*> ptr;
		ptr = mgr->getvector();
		for (int i = 0; i < ptr.size(); i++)
		{
			ptr[i]->draw(win);
		}

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

