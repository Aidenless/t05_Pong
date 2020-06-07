#pragma once

#include <string>
#include "GameObj.h"
#include "Ball.h"

class Score : public GameObj
{
public:
	static const int MAX_SCORE = 2;
	enum ScoreType { Player1, Player2 };

	Score()
		:GameObj(), mType(Player1)
	{}

	std::string scoreTxt = "0";

	void Init(ScoreType sType);

	void Update(Ball& ball);

	void UpdateScore();

private:
	ScoreType mType;

	int scoreNum = 0;
	
};