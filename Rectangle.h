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

#endif