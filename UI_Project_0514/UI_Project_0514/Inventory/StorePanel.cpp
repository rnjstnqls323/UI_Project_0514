#include "Framework.h"
#include "StorePanel.h"

StorePanel::StorePanel() : Panel(CENTER, PANEL_SIZE, RGB(255, 255, 210))
{

	LoadGoods();
}

StorePanel::~StorePanel()
{
}

void StorePanel::Update()
{
	if (!isActive)
		return;

	Panel::Update();

	for (Goods* good : GoodsManager::Get()->GetStoreGoods())
	{
		good->Update();
	}

}

void StorePanel::Render(HDC hdc)
{
	if (!isActive)
		return;

	Panel::Render(hdc);

	for (Goods* good : GoodsManager::Get()->GetStoreGoods())
	{
		good->Render(hdc);
	}

	if (selectedGood)
	{
		string text = "SelectItem : " + selectedGood->GetItemData().name;
		TextOutA(hdc, Left(), Bottom(), text.c_str(), text.length());
	}

	for (Goods* good : GoodsManager::Get()->GetStoreGoods())
	{
		if (good->IsCollisionPoint(mousePos))
		{
			good->ShowExplane(hdc);
			break; // 하나만 그려
		}
	}
}

void StorePanel::LoadGoods()
{

	//goods = GoodsManager::Get()->GetStoreGoods();
	for (Goods* good : GoodsManager::Get()->GetStoreGoods())
	{
		good->SetObjectEvent(bind(&StorePanel::OnClickGood, this, placeholders::_1));
		good->SetObjectParameter(good);
		cout << "StorePanel 바인딩됨: " << good->GetItemData().name << endl;
	}
	Vector2 leftCenter = { CENTER.x * 0.5f+30.0f,CENTER.y * 0.5f };
	Vector2 rightCenter = { leftCenter.x + 200.0f, leftCenter.y};

	int count =0;
	for (Goods* good : GoodsManager::Get()->GetStoreGoods())
	{
		if (count % 2 == 0)
		{			
			good->SetCenter({ leftCenter.x,leftCenter.y + (count / 2 * 80.f) });
		}
		else
		{
			good->SetCenter({ rightCenter.x,rightCenter.y + (count / 2 * 80.f) });
		}
		count++;
		
	}
}

void StorePanel::OnClickGood(void* good)
{
	selectedGood = (Goods*)good;
	//플레이어 골드 확인하고 구매하는 거 처리하기

	selectedGood->SetItemStatus(ItemStatus::Inventory);
	GoodsManager::Get()->UpdateStoreList();
	GoodsManager::Get()->UpdateInventoryList();

}

void StorePanel::SetActive(bool active)
{
	Panel::SetActive(active);

	if (active)
	{
		LoadGoods(); // 여기에 다시 바인딩 해줘야 함!
	}
}
