#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const RectF pos, Color c);
	void Draw(Graphics& gfx) const;
	bool checkBallCollision(const Ball& ball);
	void ExecuteBallCollision(Ball& ball);
	Vec2 GetCenter();
private:
	RectF pos{};
	Color c;
	float offset = 1;
	bool destroyed = false;
};

