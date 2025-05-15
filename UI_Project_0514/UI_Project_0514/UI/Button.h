#pragma once

class Button : public Rect
{
private:
	enum State
	{
		Normal,
		Over,
		Down
	};

public:
	Button(Vector2 center, Vector2 size);
	~Button();

	void Update();
	void Render(HDC hdc);

	void SetBrush(COLORREF normalColor, COLORREF overColor, COLORREF downColor);

	void SetText(wstring text) { this->text = text; }
	// 버튼 구현한쪽에서 누르면 자기 함수라도 넘겨주나보구나!! 대박대박
	void SetEvent(function<void()> onClick) { this->onClick = onClick; }
	void SetIntEvent(function<void(int)> onClickInt) { this->onClickInt = onClickInt; }
	void SetIntParameter(int intParameter) { this->intParameter = intParameter; }
	void SetObjectEvent(function<void(void*)> onClickObject) { this->onClickObject = onClickObject; }
	void SetObjectParameter(void* objectParameter) { this->objectParameter = objectParameter; }

	

private:
	wstring text = L"";
	State state = Normal;

	int intParameter = 0;
	void* objectParameter = nullptr;
	bool isMouseDown = false;

	HBRUSH hNormalBrush=nullptr;
	HBRUSH hOverBrush = nullptr;
	HBRUSH hDownBrush = nullptr;

	HBRUSH hSelectBrush = nullptr;

	HFONT hFont = nullptr;

	function<void()> onClick = nullptr;
	function<void(int)>onClickInt = nullptr;
	function<void(void*)> onClickObject = nullptr;
};