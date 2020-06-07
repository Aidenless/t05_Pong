#include "Wall.h"

void Wall::Update(Ball& ball)
{
	if (mType == TOP) {
		if (ball.GetPos().y - 15 <= GetPos().y) {
			ball.SetVel(Vec2f{ ball.GetVel().x, ball.GetVel().y * -1 });
		}
	}

	if (mType == BOTTOM) {
		if (ball.GetPos().y + 15 >= GetPos().y) {
			ball.SetVel(Vec2f{ ball.GetVel().x, ball.GetVel().y * -1 });
		}
	}

}