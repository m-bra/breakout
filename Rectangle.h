#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

/**
	A struct for dealing with axis-aligned rectangle geometry.
*/
struct Rectangle
{
	/// The position of the upper left corner
	float x, y;
	/// The dimensions of the rectangle
	float width, height;
};

Rectangle rect(float x, float y, float width, float height)
{
	Rectangle r;
	r.x = x;
	r.y = y;
	r.width = width;
	r.height = height;
	return r;
}

#endif
