#include <string>

#include "Score.h"
#include "Game.h"

void Score::Init(ScoreType sType) {
	mType = sType;
}

void Score::Update(Ball& ball) {
	if (mType == Player1) {
		if (ball.GetPos().x + 15 >= GDC::SCREEN_RES.x) {
			UpdateScore();
			ball.active = false;
			if (ball.player == 1) {
				ball.player = 2;
			}
			else {
				ball.player = 1;
			}
		}
	}

	if (mType == Player2) {
		if (ball.GetPos().x - 15 <= 0) {
			UpdateScore();
			ball.active = false;
			if (ball.player == 1) {
				ball.player = 2;
			}
			else {
				ball.player = 1;
			}
		}
	}
}

void Score::UpdateScore() {
	scoreNum += 1;

	scoreTxt = std::to_string(scoreNum);
}