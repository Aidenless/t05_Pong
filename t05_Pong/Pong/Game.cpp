#include <assert.h>

#include "Game.h"
#include "Application.h"

using namespace std;

Game::Game()
	: mState(StateMachine::WAITING_INIT)
{}

void Game::Initialise(sf::RenderWindow& window)
{
	assert(mState == StateMachine::WAITING_INIT);
	mGD.pWindow = &window;
	//load the font
	if (!mGD.font.loadFromFile("../bin/data/fonts/Airstream.ttf"))
		assert(false);

	mSMode.Init(this);
	mPMode.Init(this);
	mState = StateMachine::START;
}

void Game::Update()
{
	switch (mState)
	{
	case StateMachine::START:
		
		break;
	case StateMachine::PLAY:
		mPMode.Update();
		break;
	}
}

void Game::Render()
{
	switch (mState)
	{
	case StateMachine::START:
		mSMode.Render();
		break;
	case StateMachine::PLAY:
		mPMode.Render();
		break;
	}

}

void Game::TextEntered(char key)
{
	//escape overrides everything else, just quit
	switch (key)
	{
	case GDC::ESCAPE_KEY:
		mGD.pWindow->close();
		break;
	}

	//pass input messages to different mode objects
	switch (mState)
	{
	case StateMachine::START:
		mSMode.TextEntered(key);
		break;
	case StateMachine::PLAY:
		break;
	default:
		assert(false);
	}
}