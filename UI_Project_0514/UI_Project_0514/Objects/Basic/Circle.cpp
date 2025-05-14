#include "Framework.h"

Circle::Circle(int radius):Circle(radius)
{
}

Circle::~Circle()
{
}

void Circle::Render(HDC hdc)
{
	if (!isActive) return;

	Ellipse(hdc,
		center.x - radius, center.y - radius,//LeftTop
		center.x + radius, center.y + radius//RightBottom
	);
}
