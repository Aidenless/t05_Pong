#include <assert.h>
#include <string.h>
#include "Game.h"
#include "Application.h"

using namespace std;

void PlayMode::Init(Game* pG) {
	mpGame = pG;

	if (!mCourtTex.loadFromFile("../bin/data/Court.png"))
		assert(false);
	mCourtTex.setSmooth(true);
	mCourt.setTexture(mCourtTex);

	if (!mBallTex.loadFromFile("../bin/data/Ball.png"))
		assert(false);
	mBallTex.setSmooth(true);
	mBall.SetTexture(mBallTex);
	mBall.SetOrigin(Vec2f{ 15, 15 });

	if (!mWallsTex.loadFromFile("../bin/data/Walls.png"))
		assert(false);
	mWallsTex.setSmooth(true);

	mWalls[Wall::TOP].SetTexture(mWallsTex);
	mWalls[Wall::TOP].SetOrigin(Vec2f{ 600, 45 });
	mWalls[Wall::TOP].SetPos(Vec2f{ 600, GDC::SCREEN_RES.y * GDC::WALL_WIDTH });
	mWalls[Wall::TOP].Init(Wall::TOP);

	mWalls[Wall::BOTTOM].SetTexture(mWallsTex);
	mWalls[Wall::BOTTOM].SetOrigin(Vec2f{ 600, 45 });
	mWalls[Wall::BOTTOM].SetPos(Vec2f{ 600, GDC::SCREEN_RES.y * (1 - GDC::WALL_WIDTH) });
	mWalls[Wall::BOTTOM].SetDegrees(180);
	mWalls[Wall::BOTTOM].Init(Wall::BOTTOM);

	if (!mPaddleTex.loadFromFile("../bin/data/Paddle.png"))
		assert(false);
	mPaddleTex.setSmooth(true);

	if (!mPaddle2Tex.loadFromFile("../bin/data/Paddle2.png"))
		assert(false);
	mPaddleTex.setSmooth(true);

	mPaddles[Paddle::Player1].SetTexture(mPaddleTex);
	mPaddles[Paddle::Player1].SetOrigin(Vec2f{ 26, 42 });
	mPaddles[Paddle::Player1].SetPos(Vec2f{ GDC::SCREEN_RES.x * GDC::PADDLE_BUFFER, GDC::SCREEN_RES.y / 2.f });
	mPaddles[Paddle::Player1].SetScale(Vec2f{ 1.5f, 1.5f });
	mPaddles[Paddle::Player1].Init(Paddle::Player1);

	mPaddles[Paddle::Player2].SetTexture(mPaddle2Tex);
	mPaddles[Paddle::Player2].SetOrigin(Vec2f{ 0, 42 });
	mPaddles[Paddle::Player2].SetPos(Vec2f{ GDC::SCREEN_RES.x * (1 - GDC::PADDLE_BUFFER), GDC::SCREEN_RES.y / 2.f });
	mPaddles[Paddle::Player2].SetScale(Vec2f{ 1.5f, 1.5f });
	mPaddles[Paddle::Player2].Init(Paddle::Player2);

	if (!scoreFont.loadFromFile("../bin/data/fonts/digital-7.ttf"))
		assert(false);

	mScore[Score::Player1].Init(Score::Player1);

	mScore[Score::Player2].Init(Score::Player2);
}

void PlayMode::Update() {
	
	for (int i = 0; i < Paddle::MAX_PADDLES; i++)
		mPaddles[i].Update(mBall);

	if (mBall.active) {
		mBall.Update();
	}

	for (int i = 0; i < Wall::MAX_WALLS; i++) {
		mWalls[i].Update(mBall);
	}

	for (int i = 0; i < Score::MAX_SCORE; i++) {
		mScore[i].Update(mBall);
	}
}

void PlayMode::Render() {

	GD& gd = mpGame->GetData();
	gd.pWindow->draw(mCourt);

	sf::Text txt(mScore[0].scoreTxt, scoreFont, 150);
	txt.setPosition(400, 50);
	gd.pWindow->draw(txt);

	txt.setString(mScore[1].scoreTxt);
	txt.setPosition(730, 50);
	gd.pWindow->draw(txt);

	mBall.Render(*gd.pWindow);

	for (int i = 0; i < Paddle::MAX_PADDLES; i++)
		mPaddles[i].Render(*gd.pWindow);

	for (int i = 0; i < Wall::MAX_WALLS; i++)
		mWalls[i].Render(*gd.pWindow);
}