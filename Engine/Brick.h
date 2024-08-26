#include "RectF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick(const RectF pos, Color c);
	void Draw(Graphics& gfx) const;
	bool doBallCollision(Ball& ball);
private:
	RectF pos;
	Color c;
	bool destroyed = false;
};

