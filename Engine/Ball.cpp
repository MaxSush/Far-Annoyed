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
	bool collided = false;
	const RectF rect = getBallRect();
	if (rect.left < wall.left)
	{
		center.x += wall.left - rect.left;
		reboundX();
		collided = true;
	}
	else if (rect.rigth > wall.rigth)
	{
		center.x -= rect.rigth - wall.rigth;
		reboundX();
		collided = true;
	}
	if (rect.top < wall.top)
	{
		center.y += wall.top - rect.top;
		reboundY();
		collided = true;
	}
	else if (rect.bottom > wall.bottom)
	{
		center.y -= rect.bottom - wall.bottom;
		reboundY();
		collided = true;
	}
	return collided;
}

void Ball::reboundX()
{
	vel.x = -vel.x;
}

void Ball::reboundY()
{
	vel.y = -vel.y;
}

RectF Ball::getBallRect() const
{
	return RectF::getFromCenter(center, rad, rad);
}

Vec2& Ball::getCenter()
{
	return center;
}

Vec2 Ball::getBallVel() const
{
	return vel;
}

void Ball::Update(const float& dt)
{
	center += vel * dt;
}
