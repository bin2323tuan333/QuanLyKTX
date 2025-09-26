#pragma once


class Position
{
private:
	int x, y;
	bool clicked;
public:
	Position();
	~Position();
	void Update();
	int getX();
	int getY();
	bool isClicked();
	void show();
	void setClicked(bool);
};