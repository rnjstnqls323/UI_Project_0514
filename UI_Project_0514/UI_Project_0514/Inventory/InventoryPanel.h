#pragma once
//RGB(210, 255, 210)

class InventoryPanel : public Panel
{
private:
	const int COL_COUNT = 3;
	const Vector2 SPACE = Vector2(10, 10);

public:
	InventoryPanel();
	~InventoryPanel();

	void Update() override;
	void Render(HDC hdc) override;
};