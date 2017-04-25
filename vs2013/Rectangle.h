#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "cmath"

/**
	A struct for dealing with axis-aligned rectangle geometry.
*/
typedef struct Rectangle
{
	/// The position of the upper left corner
	float x, y;
	/// The dimensions of the rectangle
	float width, height;

	Rectangle(float x, float y, float width, float height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	float right() { return x + width; }

	float bottom() { return y + height; }

	bool touches(Rectangle b)
	{
		Rectangle a = *this;
		return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
			(abs(a.y - b.y) * 2 < (a.height + b.height));
	}

} rect_t;

#endif
