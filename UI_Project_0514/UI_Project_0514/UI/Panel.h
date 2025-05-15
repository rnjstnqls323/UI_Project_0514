#pragma once

class Panel : public Rect
{
private:
	const Vector2 EXPLANE_PANEL_SIZE = { 200.0f,60.0f };
public:
	Panel(Vector2 center, Vector2 size, COLORREF color);
	~Panel();

	virtual void Update();
	virtual void Render(HDC hdc);


private:
	void OnClickClose();

private:
	HBRUSH hBrush = nullptr;
	HBRUSH explaneBrush = nullptr;

	Button* closeButton = nullptr;

	Rect explanePanel;
};