#include "Framework.h"
#include "Panel.h"

Panel::Panel(Vector2 center, Vector2 size, COLORREF color) : Rect(center,size)
{
	hBrush = CreateSolidBrush(color);
    explaneBrush = CreateSolidBrush(RGB(255, 255, 200));
	closeButton = new Button(Vector2(Right(), Top()), Vector2(30, 30));
	closeButton->SetText(L"X");
	closeButton->SetBrush(
		RGB(220, 50, 50),   // Normal: 다홍 + 진한 붉은 느낌
		RGB(190, 40, 40),   // Over: 조금 더 어둡게
		RGB(150, 30, 30)    // Down: 눌렸을 때 묵직한 느낌
	);
	closeButton->SetEvent(bind(&Panel::OnClickClose, this));
}

Panel::~Panel()
{
	DeleteObject(hBrush);
	delete closeButton;
}

void Panel::Update()
{
	if (!isActive) return;

	closeButton->Update();
}

void Panel::Render(HDC hdc)
{
	if (!isActive) return;

	HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hBrush);

	Rect::Render(hdc);

	SelectObject(hdc, defaultBrush);

	closeButton->Render(hdc);

    defaultBrush = (HBRUSH)SelectObject(hdc, explaneBrush);
    ShowExplane(hdc);
    SelectObject(hdc, defaultBrush);
}

void Panel::ShowExplane(HDC hdc) //지피티 도움
{
    wstring explane = GetExplane();
    if (explane.empty()) return;

    // 1. 텍스트 크기 측정
    RECT textRect = { 0, 0, 0, 0 };
    DrawText(hdc, explane.c_str(), -1, &textRect, DT_CALCRECT | DT_LEFT | DT_WORDBREAK);

    int textWidth = textRect.right;
    int textHeight = textRect.bottom;

    // 2. 설명 패널 위치/크기 설정
    Vector2 panelPos = Vector2(mousePos.x + 15, mousePos.y + 15);
    Vector2 panelSize = Vector2(textWidth + 20, textHeight + 20); // padding

    explanePanel.SetCenter(panelPos);
    explanePanel.SetSize(panelSize);

    // 3. 패널 영역 계산
    Vector2 pos = explanePanel.GetCenter();
    Vector2 size = explanePanel.GetSize();

    RECT rect;
    rect.left = pos.x - size.x * 0.5f;
    rect.top = pos.y - size.y * 0.5f;
    rect.right = pos.x + size.x * 0.5f;
    rect.bottom = pos.y + size.y * 0.5f;

    DrawText(hdc, explane.c_str(), -1, &rect, DT_LEFT | DT_WORDBREAK);
}

void Panel::OnClickClose()
{
	isActive = false;
}
