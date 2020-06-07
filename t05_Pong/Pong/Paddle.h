#pragma once

#include "GameObj.h"
#include "Paddle.h"
#include "Ball.h"


class Paddle : public GameObj
{
public:
	static const int MAX_PADDLES = 2;
	enum PaddleType { Player1, Player2 };

	Paddle()
		:GameObj(), mType(Player1)
	{}
	void Init(PaddleType pType) {
		mType = pType;
	}
	void Update(Ball& ball);
private:
	PaddleType mType;

	float paddleSpeed = 0.1f;
	float padding = 50;
};