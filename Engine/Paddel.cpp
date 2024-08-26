#include "Paddel.h"

Paddle::Paddle(const Vec2& center, float halfWidth, float halfHeigth)
	:
	center(center),
	halfWidth(halfWidth),
	halfHeigth(halfHeigth)
{
}

void Paddle::Draw(Graphics& gfx) const
{
	RectF rect = getRect();
	gfx.DrawRect(rect, wingcolor);
	rect.left += wingwidth;
	rect.rigth -= wingwidth;
	gfx.DrawRect(rect, c);
}

void Paddle::Update(const Keyboard& kbd, const float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {
		center.x -= speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT)) {
		center.x += speed * dt;
	}
}

void Paddle::doWallCollision(const RectF& wall)
{
	RectF rect = getRect();
	if (rect.left < wall.left) {
		center.x +=  wall.left - rect.left;
	}
	else if (rect.rigth > wall.rigth) {
		center.x -= rect.rigth - wall.rigth;
	}
}

bool Paddle::doBallCollision(Ball& ball) const
{
	if (ball.getBallVel().y > 0.0f && getRect().isOverlappingWith(ball.getBallRect())) {
		ball.reboundY();
		return true;
	}
	return false;
}

RectF Paddle::getRect() const
{
	return RectF::getFromCenter(center, halfWidth, halfHeigth);
}
