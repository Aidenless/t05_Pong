#pragma once

#include "GameObj.h"
#include "Ball.h"

class Wall : public GameObj
{
public:
	static const int MAX_WALLS = 2;				//a wall on each side of the screen
	enum WallType { TOP, BOTTOM };	//identify where each wall is

	Wall()
		:GameObj(), mType(TOP)
	{}
	void Init(WallType wtype) {
		mType = wtype;
	}
	void Update(Ball& ball);
private:
	WallType mType; //where does this instance fit on screen
};