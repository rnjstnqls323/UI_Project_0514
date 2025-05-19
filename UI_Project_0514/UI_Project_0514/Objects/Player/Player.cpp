#include "Framework.h"

Player::Player():Rect({100,500}, {150,300})
{
	EventManager::Get()->AddEvent("ClickInvenItem", bind(&Player::OnSelectedItem, this, placeholders::_1));
}

Player::~Player()
{

}

void Player::Render(HDC hdc)
{
	Rect::Render(hdc);
	ShowHpBar(hdc);
}

void Player::Update()
{
}

void Player::AddItem(void* selectGood)
{
	Goods* good = static_cast<Goods*>(selectGood);
	ItemData data = good->GetItemData();


	if (gold < data.price)
	{
		MessageBox(hWnd, L"Not enough gold", L"Error", MB_OK);
		return;
	}

	// 이미 같은 이름의 아이템이 있으면 구매 불가
	for (InventoryItem* item : items)
	{
		if (item->GetItemData().name == data.name)
		{
			MessageBox(hWnd, L"This item is already purchased.", L"Error", MB_OK);
			return;
		}
	}


	Vector2 pos;
	InventoryItem* newGood = new InventoryItem(pos, data);
	items.push_back(newGood);

	gold -= data.price;
	getItems[data.name]++;
}

void Player::AddItem(ItemData data)
{
	Vector2 pos;
	InventoryItem* newGood = new InventoryItem(pos, data);
	items.push_back(newGood);

	if (data.equip)
	{
		newGood->SetEquip(true);
		equipedItem = newGood;
	}

	getItems[data.name]++;
}

void Player::RemoveItem(void* selectGood)
{
	if (selectGood == nullptr)
	{
		MessageBox(hWnd, L"선택한 아이템이 없습니다.", L"Error", MB_OK);
		return;
	}

	Goods* good = static_cast<Goods*>(selectGood);
	ItemData data = good->GetItemData();

	// 해당 이름의 아이템을 찾는다
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i]->GetItemData().name == data.name)
		{
			InventoryItem* item = items[i];
			if(item->GetEquiped() == true)
			{
				MessageBox(hWnd, L"This item was Equiped.", L"Error", MB_OK);
				return;
			}
			// 골드 추가
			gold += data.price >> 1;

			// 수량 감소
			item->AddCount(-1);
			getItems[data.name]--;

			if (item->GetCount() <= 0)
			{
				// 아이템 완전히 삭제
				delete item;
				items.erase(items.begin() + i);
			}

			return;
		}
	}

	MessageBox(hWnd, L"해당 아이템을 찾을 수 없습니다.", L"Error", MB_OK);
}

void Player::OnSelectedItem(void* item)
{
	selectedItem = (InventoryItem*)item;
}

void Player::ShowHpBar(HDC hdc)
{
	string hpText = to_string(healthPoint);
	RECT textRect = { 100, 700, 50,50 };  // 위쪽에 표시
	DrawTextA(hdc, hpText.c_str(), -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
