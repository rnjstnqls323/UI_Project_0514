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
	: Button(other)  // Button이 복사 생성자 있으면 호출
	, itemData(other.itemData)
{
	SIZE = other.SIZE;
	center = other.center;

	// 이벤트 콜백 같은 건 복사하지 말자
	// (만약 Button 클래스가 objectEvent 같은 걸 가지고 있다면, 
	// 그건 복사 생성자에서 복사 안 하도록 해야 함)
}

Goods& Goods::operator=(const Goods& other)
{
	if (this == &other) return *this;

	Button::operator=(other);
	itemData = other.itemData;
	SIZE = other.SIZE;
	center = other.center;

	// 이벤트 콜백 초기화 또는 별도 처리

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

	// 1. 텍스트 크기 측정용 RECT (임시로 1줄 최대 폭 지정)
	RECT calcRect = { 0, 0, 200, 0 }; // 최대 가로 폭 지정
	DrawTextA(hdc, explane.c_str(), -1, &calcRect, DT_CALCRECT | DT_LEFT | DT_WORDBREAK);

	int textWidth = calcRect.right - calcRect.left;
	int textHeight = calcRect.bottom - calcRect.top;

	// 2. 설명 박스 위치/크기 설정 (마우스 오른쪽 아래에 작게 띄움)
	int padding = 10;
	int panelX = static_cast<int>(mousePos.x) + 15;
	int panelY = static_cast<int>(mousePos.y) + 15;
	int panelWidth = textWidth + padding * 2;
	int panelHeight = textHeight + padding * 2;

	// 3. 설명 박스 배경 그리기
	HBRUSH brush = CreateSolidBrush(RGB(240, 240, 255)); // 연노란색 배경
	RECT backgroundRect = {
		panelX, panelY,
		panelX + panelWidth, panelY + panelHeight
	};
	FillRect(hdc, &backgroundRect, brush);
	DeleteObject(brush); // 리소스 해제

	// 4. 텍스트 그리기 (padding 적용)
	RECT textRect = {
		panelX + padding, panelY + padding,
		panelX + padding + textWidth, panelY + padding + textHeight
	};
	DrawTextA(hdc, explane.c_str(), -1, &textRect, DT_LEFT | DT_WORDBREAK);

}
