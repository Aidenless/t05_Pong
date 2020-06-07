#include "Paddle.h"
#include "Game.h"
#include "Application.h"

void Paddle::Update(Ball& ball) {
	if (mType == Player1) {
		 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (GetPos().y - 60 > GDC::SCREEN_RES.y * GDC::WALL_WIDTH)
				SetPos(Vec2f{ GetPos().x,  GetPos().y - paddleSpeed });
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (GetPos().y + 60 < GDC::SCREEN_RES.y * (1 - GDC::WALL_WIDTH))
				SetPos(Vec2f{ GetPos().x,  GetPos().y + paddleSpeed });
		}

		if (ball.player == 1) {
			if (!ball.active) {
				ball.SetPos(Vec2f{ GetPos().x + 17, GetPos().y });

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					if (GetPos().y < GDC::SCREEN_RES.y / 2.f) {
						ball.SetVel(Vec2f{ cosf(Deg2Rad(315)) * ball.speed, sinf(Deg2Rad(315)) * ball.speed });
					}
					else {
						ball.SetVel(Vec2f{ cosf(Deg2Rad(45)) * ball.speed, sinf(Deg2Rad(45)) * ball.speed });
					}

					ball.active = true;
				}
			}
		}

		if (ball.active) {
			if (ball.GetPos().x - 15 <= GetPos().x && ball.GetPos().x - 15 >= GetPos().x - 5) {
				if (ball.GetPos().y + 15 > GetPos().y - padding && ball.GetPos().y - 15 < GetPos().y + padding) {					
					ball.SetVel(Vec2f{ ball.GetVel().x * -1, ball.GetVel().y });
				}
			}
		}
	}

	if (mType == Player2) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (GetPos().y - 60 > GDC::SCREEN_RES.y * GDC::WALL_WIDTH)
				SetPos(Vec2f{ GetPos().x,  GetPos().y - paddleSpeed });
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (GetPos().y + 60 < GDC::SCREEN_RES.y * (1 - GDC::WALL_WIDTH))
				SetPos(Vec2f{ GetPos().x,  GetPos().y + paddleSpeed });
		}

		if (ball.player == 2) {
			if (!ball.active) {
				ball.SetPos(Vec2f{ GetPos().x - 17, GetPos().y });

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					if (GetPos().y < GDC::SCREEN_RES.y / 2.f) {
						ball.SetVel(Vec2f{ cosf(Deg2Rad(225)) * ball.speed, sinf(Deg2Rad(225)) * ball.speed });
					}
					else {
						ball.SetVel(Vec2f{ cosf(Deg2Rad(135)) * ball.speed, sinf(Deg2Rad(135)) * ball.speed });
					}

					ball.active = true;
				}
			}
		}

		if (ball.active) {
			if (ball.GetPos().x + 15 >= GetPos().x && ball.GetPos().x + 15 <= GetPos().x + 5) {
				if (ball.GetPos().y + 15 > GetPos().y - padding && ball.GetPos().y - 15 < GetPos().y + padding) {
					ball.SetVel(Vec2f{ ball.GetVel().x * -1, ball.GetVel().y });
				}
			}
		}
	}
}