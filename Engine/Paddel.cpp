#include "Paddel.h"

Paddel::Paddel(const Vec2& center, float halfWidth, float halfHeigth)
	:
	center(center),
	halfWidth(halfWidth),
	halfHeigth(halfHeigth)
{
}

void Paddel::Draw(Graphics& gfx) const
{
	RectF rect = getRect();
	gfx.DrawRect(rect, c);
}

void Paddel::Update(const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_LEFT)) {
		center.x -= 5;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT)) {
		center.x += 5;
	}
}

void Paddel::doWallCollision(const RectF& wall)
{
	RectF rect = getRect();
	if (rect.left < wall.left) {
		center.x +=  wall.left - rect.left;
	}
	else if (rect.rigth > wall.rigth) {
		center.x -= rect.rigth - wall.rigth;
	}
}

void Paddel::doBallCollision(Ball& ball) const
{
	RectF rect = getRect();
	if (rect.isOverlappingWith(ball.getBallRect())) {
		if (ball.getBallVel().x < 0) {
			ball.reboundY();
		}
		else {
			ball.reboundY();
		}
	}
}

RectF Paddel::getRect() const
{
	return RectF::getFromCenter(center, halfWidth, halfHeigth);
}
