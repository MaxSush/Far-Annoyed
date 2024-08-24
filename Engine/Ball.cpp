#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& center, const Vec2& vel)
	:
	center(center),
	vel(vel)
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(center, gfx);
}

bool Ball::doWallColision(const RectF& wall)
{
	RectF rect = getRect();
	float dt = 0.0f;
	if (rect.left < wall.left + dt) {
		center.x += wall.left - rect.left;
		reboundX();
	}
	else if (rect.rigth > wall.rigth - dt) {
		center.x -= rect.rigth - wall.rigth;
		reboundX();
	}
	if (rect.top < wall.top + dt) {
		center.y += wall.top - rect.top;
		reboundY();
	}
	else if (rect.bottom > wall.bottom - dt) {
		center.y -= rect.bottom - wall.bottom;
		reboundY();
	}
	return false;
}

void Ball::reboundX()
{
	vel.x = -vel.x;
}

void Ball::reboundY()
{
	vel.y = -vel.y;
}

RectF Ball::getRect() const
{
	return RectF::getFromCenter(center, rad);
}

void Ball::Update(const float& dt)
{
	center += vel * dt;
}
