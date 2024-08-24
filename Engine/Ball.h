#pragma once
#include "Vec2.h"
#include "Graphics.h"
class Ball
{
public:
	Ball( const Vec2& center, const Vec2& vel);
	void Draw(Graphics& gfx) const;
	void Update(const float& dt);
	bool doWallColision(const RectF& wall);
	void reboundX();
	void reboundY();
	RectF getRect() const;
private:
	static constexpr float rad = 7.0f;
	Vec2 center;
	Vec2 vel;
};

