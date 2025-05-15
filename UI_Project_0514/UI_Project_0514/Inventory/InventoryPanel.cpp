#include "Framework.h"

InventoryPanel::InventoryPanel():Panel(CENTER, PANEL_SIZE,RGB(210, 255, 210))
{

	LoadGoods();
}

InventoryPanel::~InventoryPanel()
{
}

void InventoryPanel::Update()
{
	if (!isActive)
		return;
	Panel::Update();

	for (Goods* good : GoodsManager::Get()->GetInventoryGoods()) //중복호출되는듯
	{
		good->Update();
	}
}

void InventoryPanel::Render(HDC hdc)
{
	if (!isActive)
		return;

	Panel::Render(hdc);

	for (Goods* good : GoodsManager::Get()->GetInventoryGoods())
	{
		good->Render(hdc);
	}

	if (selectedGood)
	{
		string text = "SelectItem : " + selectedGood->GetItemData().name;
		TextOutA(hdc, Left(), Bottom(), text.c_str(), text.length());
	}

	for (Goods* good : GoodsManager::Get()->GetInventoryGoods())
	{
		if (good->IsCollisionPoint(mousePos))
		{
			good->ShowExplane(hdc);
			break; // 하나만 그려
		}
	}
}

void InventoryPanel::SetActive(bool active)
{
	Panel::SetActive(active);

	if (active)
	{
		LoadGoods(); // 여기에 다시 바인딩 해줘야 함!
	}
}

void InventoryPanel::LoadGoods()
{
	//goods = GoodsManager::Get()->GetInventoryGoods();

	for (Goods* good : GoodsManager::Get()->GetInventoryGoods())
	{
		Goods* copyGood = new Goods(*good);  // 복사 생성자 호출
		copyGood->SetObjectEvent(bind(&InventoryPanel::OnClickGood, this, placeholders::_1));
		copyGood->SetObjectParameter(copyGood);
	}

	Vector2 leftCenter = { CENTER.x * 0.5f,CENTER.y * 0.5f };
	Vector2 rightCenter = { leftCenter.x + 200.0f, leftCenter.y };

	int count = 0;
	for (Goods* good : GoodsManager::Get()->GetInventoryGoods())
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

void InventoryPanel::OnClickGood(void* good)
{
	selectedGood = (Goods*)good;

	// 장착된 모든 아이템 해제
	vector<Goods*> equip = GoodsManager::Get()->GetEquipGoods();
	for (Goods* good : equip)
	{
		good->SetItemStatus(ItemStatus::Inventory);
	}

	// 선택한 아이템 장착 상태로 변경
	selectedGood->SetItemStatus(ItemStatus::Equipped);

	// 리스트 업데이트
	GoodsManager::Get()->UpdateInventoryList();
	GoodsManager::Get()->UpdateEquipList();
}
