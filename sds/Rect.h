#pragma once
class Rect
{
public:
	int left_x;
	int upper_y;
	int right_x;
	int bottom_y;
	Rect(int x1, int x2, int y1, int y2):left_x(x1),right_x(x2),upper_y(y1),bottom_y(y2){}
	~Rect(void);
	static bool isOverlap(Rect* rect);
};

