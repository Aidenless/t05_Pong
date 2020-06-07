#pragma once

#include "GameObj.h"

struct Ball : public GameObj
{
public:
	Ball()
		:GameObj()
	{}

	bool active = false;
	float speed = 800;
	float player = 1;
};