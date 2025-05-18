#include "Framework.h"
#include "Monster.h"

Monster::Monster():Circle(100)
{
	this->SetCenter({ 400,150 });
}

Monster::~Monster()
{
}

void Monster::Render(HDC hdc)
{
	Circle::Render(hdc);
}

void Monster::Update()
{
}

void Monster::Die()
{
}

void Monster::Fight()
{
}
