#pragma once
#include "Vec2.h"
class RectF
{
public:
	RectF(float left, float top, float rigth, float bootom);
	RectF(const Vec2& top_left, const Vec2& bottom_rigth);
	RectF(const Vec2& top_left, float width, float heigth);
	bool isOverlappingWith(const RectF& other) const;
private:
	float top;
	float rigth;
	float left;
	float bottom;
};

