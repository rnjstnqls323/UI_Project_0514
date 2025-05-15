#include "Framework.h"

EquipPanel::EquipPanel() :Panel(CENTER, PANEL_SIZE, RGB(255, 240, 220))
{
	LoadGoods();
}

EquipPanel::~EquipPanel()
{
}

void EquipPanel::Update()
{
	if (!isActive)
		return;
	Panel::Update();

	for (Goods* good : GoodsManager::Get()->GetEquipGoods()) //중복호출되는듯
	{
		good->Update();
	}
}

void EquipPanel::Render(HDC hdc)
{
	if (!isActive)
		return;

	Panel::Render(hdc);

	for (Goods* good : GoodsManager::Get()->GetEquipGoods())
	{
		good->Render(hdc);
	}

	if (selectedGood)
	{
		string text = "SelectItem : " + selectedGood->GetItemData().name;
		TextOutA(hdc, Left(), Bottom(), text.c_str(), text.length());
	}

	for (Goods* good : GoodsManager::Get()->GetEquipGoods())
	{
		if (good->IsCollisionPoint(mousePos))
		{
			good->ShowExplane(hdc);
			break; // 하나만 그려
		}
	}
}

void EquipPanel::LoadGoods()
{
	//goods = GoodsManager::Get()->GetEquipGoods();
	//vector<Goods*> good = GoodsManager::Get()->GetEquipGoods();
	for (Goods* good : GoodsManager::Get()->GetEquipGoods())
	{
		good->SetObjectEvent(bind(&EquipPanel::OnClickGood, this, placeholders::_1));
		good->SetObjectParameter(good);
	}

	Vector2 leftCenter = { CENTER.x * 0.5f,CENTER.y * 0.5f };
	Vector2 rightCenter = { leftCenter.x + 200.0f, leftCenter.y };

	int count = 0;
	for (Goods* good : GoodsManager::Get()->GetEquipGoods())
	{
		if (count % 2 == 0)
		{
			good->SetCenter({ leftCenter.x,leftCenter.y + (count / 2 * 50.f) });
		}
		else
		{
			good->SetCenter({ rightCenter.x,rightCenter.y + (count / 2 * 50.f) });
		}
		count++;

	}
}

void EquipPanel::OnClickGood(void* good)
{
	selectedGood = (Goods*)good;

	selectedGood->SetItemStatus(ItemStatus::Inventory);

	GoodsManager::Get()->UpdateEquipList();
	GoodsManager::Get()->UpdateInventoryList();
}
