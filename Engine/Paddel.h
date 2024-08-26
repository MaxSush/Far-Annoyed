#pragma once
#include "RectF.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Ball.h"

class Paddel
{
public:
	Paddel(const Vec2& center, float halfWidth, float halfHeigth);
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd);
	void doWallCollision(const RectF& wall);
	void doBallCollision(Ball& ball) const;
	RectF getRect() const;
private:
	static constexpr int left_border = 0;
	static constexpr int rigth_border = 800;
	float halfWidth;
	float halfHeigth;
	Vec2 center;
	static constexpr Color c = Colors::LightGray;
};

