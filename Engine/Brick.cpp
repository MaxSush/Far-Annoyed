#include "Brick.h"
#include <assert.h>
#include <cmath>

Brick::Brick(const RectF pos, Color c)
	:
	pos(pos),
	c(c)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed) {

		gfx.DrawRect(pos.getRectOffset(offset), c);
	}
}

bool Brick::checkBallCollision(const Ball& ball)
{
	return (!destroyed && pos.isOverlappingWith(ball.getBallRect()));

}

void Brick::ExecuteBallCollision(Ball& ball)
{
	assert(checkBallCollision(ball));
	const Vec2 ballPos = ball.getCenter();
	if (std::signbit(ball.getBallVel().x) == std::signbit((ballPos - GetCenter()).x))
	{
		ball.reboundY();
	}
	else if (ballPos.x >= pos.left && ballPos.x <= pos.rigth)
	{
		ball.reboundY();
	}
	else
	{
		ball.reboundX();
	}
	destroyed = true;
}

Vec2 Brick::GetCenter()
{
	return Vec2((pos.rigth + pos.left) / 2.0f, (pos.bottom + pos.top) / 2.0f);
}
