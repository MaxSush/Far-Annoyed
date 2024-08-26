#include "Brick.h"
#include <assert.h>

Brick::Brick(const RectF pos, Color c)
	:
	pos(pos),
	c(c)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed) {
		gfx.DrawRect(pos, c);
	}
}

bool Brick::doBallCollision(Ball& ball)
{
	if (!destroyed && pos.isOverlappingWith(ball.getBallRect())) {
		ball.reboundY();
		destroyed = true;
		return true;
	}
	return false;
}