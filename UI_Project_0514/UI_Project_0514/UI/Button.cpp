#include "Framework.h"

Button::Button(Vector2 center, Vector2 size):Rect(center,size)
{
	hFont = CreateFont(20, 0, 0, 0, FW_BOLD, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"����ǹ��� ������ü TTF");
}

Button::~Button()
{
	DeleteObject(hFont);
	if (hNormalBrush)
		DeleteObject(hNormalBrush);
	if (hOverBrush)
		DeleteObject(hOverBrush);
	if (hDownBrush)
		DeleteObject(hDownBrush);

}

void Button::Update()
{
	if (!isActive) return;

	if (IsCollisionPoint(mousePos)) // ��ư ���� ���콺������ �� �ٲٰ�, ������ �� �ٲٰ�~!
	{
		state = Over;
		if (Input::Get()->IsKeyPress(VK_LBUTTON))
		{
			state = Down;
			isMouseDown = true;
		}
		if (Input::Get()->IsKeyUp(VK_LBUTTON))
		{
			isMouseDown = false;
			if (onClick) onClick();
			if (onClickInt) onClickInt(intParameter);
			if (onClickObject) onClickObject(objectParameter);
		}
		else
			state = Normal;

	}

	switch (state)
	{
	case Button::Normal:
		hSelectBrush = hNormalBrush;
		break;
	case Button::Over:
		hSelectBrush = hOverBrush;
		break;
	case Button::Down:
		hSelectBrush = hDownBrush;
		break;
	}
}

void Button::Render(HDC hdc)
{ //�׸� �׸��鼭 �۾�ü �ٲ㼭 ������ ���ش�
	if (!isActive) return;

	HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hSelectBrush);
	Rect::Render(hdc);

	SelectObject(hdc, defaultBrush);

	RECT rect = { Left(), Top(), Right(), Bottom() };
	HFONT defaultFont = (HFONT)SelectObject(hdc, hFont);
	DrawText(hdc, text.c_str(), text.length(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	SelectObject(hdc, defaultFont);
}

void Button::SetBrush(COLORREF normalColor, COLORREF overColor, COLORREF downColor)
{ //���� �� �޾Ƽ� ���� �ٽ����ֳ�
	if (hNormalBrush)
		DeleteObject(hNormalBrush);
	hNormalBrush = CreateSolidBrush(normalColor);

	if (hOverBrush)
		DeleteObject(hOverBrush);
	hOverBrush = CreateSolidBrush(overColor);

	if (hDownBrush)
		DeleteObject(hDownBrush);
	hDownBrush = CreateSolidBrush(downColor);
}
