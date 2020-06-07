#pragma once

#include "SFML/Graphics.hpp"

//dimensions in 2D that are whole numbers
struct Vec2i
{
	int x, y;
};

//dimensions in 2D that are floating point numbers
struct Vec2f
{
	float x, y;
};

class GameObj
{
public:
	GameObj() : mVel{ 0, 0 } {};
	void Update();
	void Render(sf::RenderWindow& window) {
		window.draw(mSprite);
	}
	void SetTexture(const sf::Texture & t) {
		mSprite.setTexture(t, true);
	}
	void SetTexture(const sf::Texture& t, const sf::IntRect& rect) {
		mSprite.setTexture(t);
		mSprite.setTextureRect(rect);
	}
	void SetOrigin(const Vec2f& off) {
		mSprite.setOrigin(sf::Vector2f(off.x, off.y));
	}
	void SetScale(const Vec2f& s) {
		mSprite.setScale(s.x, s.y);
	}
	Vec2f GetScale() {
		return Vec2f{ mSprite.getScale().x, mSprite.getScale().y };
	}
	Vec2f GetPos() {
		return Vec2f{ mSprite.getPosition().x,mSprite.getPosition().y };
	}
	void SetPos(const Vec2f& pos) {
		mSprite.setPosition(pos.x, pos.y);
	}
	void SetTextPos(const Vec2f& pos) {
		mText.setPosition(pos.x, pos.y);
	}
	float GetDegrees() {
		return mSprite.getRotation();
	}
	void SetDegrees(float angle) {
		mSprite.setRotation(angle);
	}
	void AddRotation(float angle) {
		mSprite.rotate(angle);
	}
	void SetVel(const Vec2f& v) {
		mVel.x = v.x;
		mVel.y = v.y;
	}
	const Vec2f GetVel() const {
		return Vec2f{ mVel.x,mVel.y };
	}
	Vec2f GetDim() const {
		return Vec2f{ (float)mSprite.getTextureRect().width, (float)mSprite.getTextureRect().height };
	}

private:
	sf::Sprite mSprite; //image and position
	sf::Text mText;
	sf::Vector2f mVel;	//velocity
};