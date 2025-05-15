#include "Framework.h"
#include "Goods.h"

Goods::Goods(Vector2 center, ItemData itemData)
	: Button(center, Vector2(120, 50)), itemData(itemData)
{
	SetBrush(RGB(255, 255, 150), RGB(255, 230, 120), RGB(255, 200, 80));
}

Goods::~Goods()
{
}
Goods::Goods(const Goods& other)
	: Button(other)  // Button�� ���� ������ ������ ȣ��
	, itemData(other.itemData)
{
	SIZE = other.SIZE;
	center = other.center;

	// �̺�Ʈ �ݹ� ���� �� �������� ����
	// (���� Button Ŭ������ objectEvent ���� �� ������ �ִٸ�, 
	// �װ� ���� �����ڿ��� ���� �� �ϵ��� �ؾ� ��)
}

Goods& Goods::operator=(const Goods& other)
{
	if (this == &other) return *this;

	Button::operator=(other);
	itemData = other.itemData;
	SIZE = other.SIZE;
	center = other.center;

	// �̺�Ʈ �ݹ� �ʱ�ȭ �Ǵ� ���� ó��

	return *this;
}

void Goods::Render(HDC hdc)
{
	Button::Render(hdc);

	string text = "Name : " + itemData.name;
	TextOutA(hdc, Left() + 10, Top() + 10, text.c_str(), text.length());
	text = "Price : " + to_string(itemData.price);
	TextOutA(hdc, Left() + 10, Top() + 30, text.c_str(), text.length());
}

void Goods::ShowExplane(HDC hdc)
{
	string explane = itemData.explane;
	if (explane.empty()) return;

	// 1. �ؽ�Ʈ ũ�� ������ RECT (�ӽ÷� 1�� �ִ� �� ����)
	RECT calcRect = { 0, 0, 200, 0 }; // �ִ� ���� �� ����
	DrawTextA(hdc, explane.c_str(), -1, &calcRect, DT_CALCRECT | DT_LEFT | DT_WORDBREAK);

	int textWidth = calcRect.right - calcRect.left;
	int textHeight = calcRect.bottom - calcRect.top;

	// 2. ���� �ڽ� ��ġ/ũ�� ���� (���콺 ������ �Ʒ��� �۰� ���)
	int padding = 10;
	int panelX = static_cast<int>(mousePos.x) + 15;
	int panelY = static_cast<int>(mousePos.y) + 15;
	int panelWidth = textWidth + padding * 2;
	int panelHeight = textHeight + padding * 2;

	// 3. ���� �ڽ� ��� �׸���
	HBRUSH brush = CreateSolidBrush(RGB(240, 240, 255)); // ������� ���
	RECT backgroundRect = {
		panelX, panelY,
		panelX + panelWidth, panelY + panelHeight
	};
	FillRect(hdc, &backgroundRect, brush);
	DeleteObject(brush); // ���ҽ� ����

	// 4. �ؽ�Ʈ �׸��� (padding ����)
	RECT textRect = {
		panelX + padding, panelY + padding,
		panelX + padding + textWidth, panelY + padding + textHeight
	};
	DrawTextA(hdc, explane.c_str(), -1, &textRect, DT_LEFT | DT_WORDBREAK);

}
