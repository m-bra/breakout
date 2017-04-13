#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include "GameObject.h"

#define MAX_OBJECTS 64

class World
{
public:



private:
	GameObject *objects[MAX_OBJECTS];
};

#endif