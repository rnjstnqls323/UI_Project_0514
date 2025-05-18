#include "Framework.h"

InventoryPanel::InventoryPanel():Panel(CENTER, PANEL_SIZE,RGB(210, 255, 210))
{

}

InventoryPanel::~InventoryPanel()
{
}

void InventoryPanel::Update()
{
	if (!isActive)
		return;

	Panel::Update();

	int columns = 3;
	int spacing = 10;
	int index = 0;

	for (InventoryItem* item : Player::Get()->items)
	{
		Vector2 itemSize = item->GetSize();

		int row = index / columns;
		int col = index % columns;

		// 각 아이템의 위치 계산
		Vector2 startPos(
			Left() + (itemSize.x+30 + spacing) * col,
			Top() + (itemSize.y + spacing) * row
		);

		item->SetCenter(startPos + itemSize * 0.5f); // 중심 위치로
		item->Update();
		index++;
	}
}

void InventoryPanel::Render(HDC hdc)
{
	if (!isActive)
		return;

	Panel::Render(hdc);

	for (InventoryItem* item : Player::Get()->items)
	{
		item->Render(hdc);
	}
}
