#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Ball.h"

class Paddle
{
public:
	Paddle(const Vec2& center, float halfWidth, float halfHeigth);
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd, const float dt);
	void doWallCollision(const RectF& wall);
	bool doBallCollision(Ball& ball) const;
	RectF getRect() const;
private:
	float halfWidth;
	float halfHeigth;
	float speed = 300.0f;
	float wingwidth = 10;
	Color wingcolor = Colors::Magenta;
	Vec2 center;
	static constexpr Color c = Colors::LightGray;
};

