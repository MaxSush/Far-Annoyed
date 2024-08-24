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

bool Brick::checkBallCollision(const Ball& ball) const
{
	return pos.isOverlappingWith(ball.getRect());
}