#pragma once

#include <string>

#include "SFML/Graphics.hpp"
#include "GameObj.h"
#include "Wall.h"
#include "Ball.h"
#include "Paddle.h"
#include "Score.h"

const float PI = 3.14159265358979323846f;
inline float Deg2Rad(float deg) {
	return deg * (PI / 180.f);
}

namespace GDC
{
	const Vec2i SCREEN_RES{ 1200,800 };	//desired resolution
	const char ESCAPE_KEY{ 27 };		//ASCII code
	const char ENTER_KEY{ 13 };
	const sf::Uint32 ASCII_RANGE{ 127 };//google an ASCII table, after 127 we don't care
	const float WALL_WIDTH{ 0.08f };
	const float PADDLE_BUFFER{ 0.05f };
}

struct GD
{
	sf::Font font;				//a shared font to use everywhere
	sf::RenderWindow* pWindow;	//can't render anything without this
};

class Game;

class StartMode
{
public:
	StartMode() :mpGame(nullptr) {}

	void Init(Game*);

	void Update() {};

	void Render();

	void TextEntered(char);

private:
	Game* mpGame;

	sf::Texture mStartScreenTex;

	sf::Sprite mStartScreen;
};

class PlayMode
{
public:
	PlayMode() : mpGame(nullptr) {}
	void Init(Game*);
	void Update();
	void Render();
private:
	Game* mpGame; //for communication

	sf::Texture mCourtTex;	
	sf::Texture mWallsTex;
	sf::Texture mBallTex;
	sf::Texture mPaddleTex;
	sf::Texture mPaddle2Tex;

	sf::Font scoreFont;

	sf::Sprite mCourt;
	Wall mWalls[Wall::MAX_WALLS];
	Ball mBall;
	Paddle mPaddles[Paddle::MAX_PADDLES];
	Score mScore[Score::MAX_SCORE];
};

class Game
{
public:
	//control what the game is doing 
	enum class StateMachine {
		WAITING_INIT,	//not in a safe state yet
		START,		
		PLAY			//let's play!!
	};

	Game();
	
	void Initialise(sf::RenderWindow&);
	
	void Update();
	
	void Render();
	
	void TextEntered(char);

	StateMachine& GetState() { return mState; }
	void SetState(StateMachine nState) { mState = nState; }

	GD& GetData() { return mGD; }
private:
	GD mGD;				
	StateMachine mState;
	PlayMode mPMode;
	StartMode mSMode;
};