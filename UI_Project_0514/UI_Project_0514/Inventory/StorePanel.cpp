#include "Framework.h"
#include "StorePanel.h"

StorePanel::StorePanel()
	:Panel(CENTER, PANEL_SIZE, RGB(255, 214, 170))
{
	CreateGoods();

	buyButton = new Button(Vector2(Left() + 50, Bottom() - 50), Vector2(100, 50));
	buyButton->SetText(L"Buy");
	buyButton->SetBrush(RGB(170, 255, 204), RGB(140, 220, 180), RGB(110, 190, 150));
	buyButton->SetEvent(bind(&StorePanel::BuyItem, this));

	sellButton = new Button(Vector2(Right() - 50, Bottom() - 50), Vector2(100, 50));
	sellButton->SetText(L"Sell");
	sellButton->SetBrush(RGB(255, 204, 204), RGB(255, 170, 170), RGB(255, 140, 140));
	sellButton->SetEvent(bind(&StorePanel::SellItem, this));
}

StorePanel::~StorePanel()
{
	delete buyButton;
	delete sellButton;

	for (Goods* good : goods)
	{
		delete good;
	}
}

void StorePanel::Update()
{
	if (!isActive)
		return;

	if (Input::Get()->IsKeyDown(VK_F2))
	{
		BuyItem();
	}

	Panel::Update();

	for (Goods* good : goods)
	{
		good->Update();
	}

	buyButton->Update();
	sellButton->Update();
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

	buyButton->Render(hdc);
	sellButton->Render(hdc);

	
}

void StorePanel::CreateGoods()
{
	int itemCount = ItemDataManager::Get()->GetItemCount();

	for (int i = 0; i < itemCount; i++)
	{
		ItemData itemData = ItemDataManager::Get()->GetItem(1000 + i);
		Vector2 pos;
		pos.x = center.x;
		pos.y = Top() + 30+ i * 80;

		Goods* good = new Goods(pos, itemData);
		good->SetObjectEvent(bind(&StorePanel::OnClickGood, this, placeholders::_1));
		good->SetObjectParameter(good);
		goods.push_back(good);
	}
}

void StorePanel::BuyItem()
{
	if (selectedGood == nullptr)
		return;

	//EventManager::Get()->ExcuteEvent("AddItem", selectedGood);
	//inventoryPanel->AddItem(selectedGood);
	Player::Get()->AddItem(selectedGood);
}

void StorePanel::SellItem()
{
	if (selectedGood == nullptr)
		return;
	
	Player::Get()->RemoveItem(selectedGood);
}

void StorePanel::OnClickGood(void* good)
{
	selectedGood = (Goods*)good;
}
