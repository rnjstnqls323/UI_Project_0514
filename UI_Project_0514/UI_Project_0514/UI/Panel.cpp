#include "Framework.h"
#include "Panel.h"

Panel::Panel(Vector2 center, Vector2 size, COLORREF color) : Rect(center,size)
{
	hBrush = CreateSolidBrush(color);
    explaneBrush = CreateSolidBrush(RGB(255, 255, 200));
	closeButton = new Button(Vector2(Right(), Top()), Vector2(30, 30));
	closeButton->SetText(L"X");
	closeButton->SetBrush(
		RGB(220, 50, 50),   // Normal: ´ÙÈ« + ÁøÇÑ ºÓÀº ´À³¦
		RGB(190, 40, 40),   // Over: Á¶±Ý ´õ ¾îµÓ°Ô
		RGB(150, 30, 30)    // Down: ´­·ÈÀ» ¶§ ¹¬Á÷ÇÑ ´À³¦
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
    SelectObject(hdc, defaultBrush);
}

void Panel::OnClickClose()
{
	isActive = false;
}
