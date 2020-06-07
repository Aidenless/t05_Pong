#include <assert.h>

#include "Game.h"

using namespace std;

void StartMode::Init(Game* pG) {
	assert(!mpGame);
	mpGame = pG;

	if (!mStartScreenTex.loadFromFile("../bin/data/pingpongsplash.png"))
		assert(false);
	mStartScreenTex.setSmooth(true);
	mStartScreen.setTexture(mStartScreenTex);
	mStartScreen.setScale(1.7, 1.7);
}

void StartMode::TextEntered(char key) {
	if (key == GDC::ENTER_KEY) {
		mpGame->SetState(Game::StateMachine::PLAY);
	}
}

void StartMode::Render() {
	GD& gd = mpGame->GetData();

	gd.pWindow->draw(mStartScreen);

	string mssg = "Press enter to play";
	sf::Text txt(mssg, gd.font, 60);
	txt.setPosition(400, 600);
	gd.pWindow->draw(txt);
}