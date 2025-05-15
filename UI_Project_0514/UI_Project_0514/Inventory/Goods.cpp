#include "Framework.h"
#include "Goods.h"

Goods::Goods(Vector2 center, ItemData itemData) : Button(center, SIZE),itemData(itemData)
{
	SetBrush(RGB(255, 255, 150), RGB(255, 230, 120), RGB(255, 200, 80));
}

Goods::~Goods()
{
}

void Goods::Render(HDC hdc)
{
	Button::Render(hdc);

	string text = "Name : " + itemData.name;
	TextOutA(hdc, Left() + 10, Top() + 10, text.c_str(), text.length());
	text = "Price : " + to_string(itemData.price);
	TextOutA(hdc, Left() + 10, Top() + 30, text.c_str(), text.length());
}
