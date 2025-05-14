#pragma once

class Circle : public GameObject
{
public:
	Circle(int radius);
	~Circle();

	void Render(HDC hdc);

protected:
	int radius;
};