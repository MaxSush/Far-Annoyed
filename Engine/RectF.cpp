#include "RectF.h"

RectF::RectF(float left, float top, float rigth, float bottom)
	:
	top(top),
	left(left),
	rigth(rigth),
	bottom(bottom)
{
}

RectF::RectF(const Vec2& top_left, const Vec2& bottom_rigth)
	:
	RectF(top_left.x, top_left.y, bottom_rigth.x, bottom_rigth.y)
{
}

RectF::RectF(const Vec2& top_left, float width, float heigth)
	:
	RectF(top_left.x, top_left.y, width, heigth)
{
}

bool RectF::isOverlappingWith(const RectF& other) const
{
	return left >= other.left && rigth <= other.rigth &&
		top >= other.top && bottom <= other.bottom;
}
