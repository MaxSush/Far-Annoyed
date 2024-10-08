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
	RectF(top_left, top_left + Vec2(width, heigth))
{
}

RectF RectF::getFromCenter(const Vec2& center_pos, float width, float heigth)
{
	Vec2 half(width, heigth);
	return RectF(center_pos - half, center_pos + half);
}

bool RectF::isOverlappingWith(const RectF& other) const
{
	return left < other.rigth && top < other.bottom
		&& rigth > other.left && bottom > other.top;
}

RectF RectF::getRectOffset(float offset) const
{
	return RectF(left + offset, top + offset, rigth - offset, bottom - offset);

}
