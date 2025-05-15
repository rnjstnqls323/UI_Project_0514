#include "Framework.h"
#include "StroePanel.h"

StorePanel::StorePanel() : Panel(CENTER, PANEL_SIZE, RGB(255, 255, 210))
{
}

StorePanel::~StorePanel()
{
}

void StorePanel::Update()
{
	if (!isActive)
		return;

	Panel::Update();

	for (Goods* good : goods)
	{
		good->Update();
	}
}

void StorePanel::Render(HDC hdc)
{
	if (!isActive)
		return;

	Panel::Render(hdc);

	for (Goods* good : goods)
	{
		good->Render(hdc);
	}

	if (selectedGood)
	{
		string text = "SelectItem : " + selectedGood->GetItemData().name;
		TextOutA(hdc, Left(), Bottom(), text.c_str(), text.length());
	}
}

void StorePanel::CreateGoods()
{
	int itemCount = ItemDataManager::Get()->GetItemCount();

	for (int i = 0; i < itemCount; i++)
	{
		ItemData itemData = ItemDataManager::Get()->GetItem(1000 + i + 1);
		Vector2 pos;
		pos.x = center.x;
		pos.y = Top() + 50 + i * 100;

		Goods* good = new Goods(pos, itemData);
		good->SetObjectEvent(bind(&StorePanel::OnClickGood, this, placeholders::_1));
		good->SetObjectParameter(good);
		goods.push_back(good);
	}
}

void StorePanel::OnClickGood(void* good)
{
	selectedGood = (Goods*)good;
}
