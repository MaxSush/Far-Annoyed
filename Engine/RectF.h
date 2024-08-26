#pragma once
#include "Vec2.h"
class RectF
{
public:
	RectF() = default;
	RectF(float left, float top, float rigth, float bottom);
	RectF(const Vec2& top_left, const Vec2& bottom_rigth);
	RectF(const Vec2& top_left, float width, float heigth);
	static RectF getFromCenter(const Vec2& center_pos, float width, float heigth);
	bool isOverlappingWith(const RectF& other) const;
	RectF getRectOffset(float offset) const;
public:
	float top;
	float rigth;
	float left;
	float bottom;
};

