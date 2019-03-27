#include "SettingsUI.h"

SettingsUI::SettingsUI(SettingsMgr *mgr)
{
	//this constructor is initialized with data from the file through the settings manager
	ptr = mgr;
}
void SettingsUI::handleMouseUp(Vector2f mouse)
{
	if (bluebtn.getGlobalBounds().contains(mouse))
	{
		ptr->setcurrentColor(Color::Blue);
	}
	else if (greenbtn.getGlobalBounds().contains(mouse))
	{
		ptr->setcurrentColor(Color::Green);
	}
	else if (redbtn.getGlobalBounds().contains(mouse))
	{
		ptr->setcurrentColor(Color::Red);
	}

	if (circlebtn.getGlobalBounds().contains(mouse))
	{
		ptr->setcurrentShape(CIRCLE);
	}
	else if (rectbtn.getGlobalBounds().contains(mouse))
	{
		ptr->setcurrentShape(SQUARE);
	}
}

void SettingsUI::draw(RenderWindow& win)
{

	Vector2f pos1(75, 100);
	bluebtn.setPosition(pos1);
	bluebtn.setRadius(20);
	bluebtn.setOutlineThickness(2);
	bluebtn.setOutlineColor(Color::Blue);
	bluebtn.setFillColor(Color::Transparent);

	Vector2f pos2(75, 150);
	greenbtn.setPosition(pos2);
	greenbtn.setRadius(20);
	greenbtn.setOutlineThickness(2);
	greenbtn.setOutlineColor(Color::Green);
	greenbtn.setFillColor(Color::Transparent);

	Vector2f pos3(75, 200);
	redbtn.setPosition(pos3);
	redbtn.setRadius(20);
	redbtn.setOutlineThickness(2);
	redbtn.setOutlineColor(Color::Red);
	redbtn.setFillColor(Color::Transparent);

	Vector2f pos4(75, 325);
	circlebtn.setPosition(pos4);
	circlebtn.setRadius(20);
	circlebtn.setOutlineThickness(2);
	circlebtn.setOutlineColor(Color::White);
	circlebtn.setFillColor(Color::Transparent);

	Vector2f pos5(75, 400);
	rectbtn.setPosition(pos5);
	rectbtn.setOutlineColor(Color::White);
	rectbtn.setOutlineThickness(2);
	rectbtn.setSize(Vector2f(35, 35));
	rectbtn.setFillColor(Color::Transparent);

	if (ptr->getCurColor() == Color::Blue)
	{
		bluebtn.setFillColor(Color::Blue);
	}
	else if (ptr->getCurColor() == Color::Green)
	{
		greenbtn.setFillColor(Color::Green);
	}
	else if (ptr->getCurColor() == Color::Red)
	{
		redbtn.setFillColor(Color::Red);
	}
	else
	{
		cout << "error" << endl;
	}

	if (ptr->getCurShape() == CIRCLE)
	{
		circlebtn.setFillColor(Color::White);
	}
	else if (ptr->getCurShape() == SQUARE)
	{
		rectbtn.setFillColor(Color::White);
	}
	else
	{
		cout << "error" << endl;
	}
	win.draw(bluebtn);
	win.draw(greenbtn);
	win.draw(redbtn);
	win.draw(circlebtn);
	win.draw(rectbtn);


}