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
	ShowBar(hdc);
}

void Monster::Update()
{
}

bool Monster::IsDie()
{
	if (this->healthPoint <= 0)
		return true;
	else
		return false;
}

void Monster::Fight()
{
}
void Monster::ShowBar(HDC hdc)
{
	string hpText = to_string(healthPoint);
	RECT textRect = { 700, 150, 50,50 };  // 위쪽에 표시
	DrawTextA(hdc, hpText.c_str(), -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
