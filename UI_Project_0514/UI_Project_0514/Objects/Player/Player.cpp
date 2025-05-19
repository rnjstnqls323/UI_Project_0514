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

	// �̹� ���� �̸��� �������� ������ ���� �Ұ�
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
		MessageBox(hWnd, L"������ �������� �����ϴ�.", L"Error", MB_OK);
		return;
	}

	Goods* good = static_cast<Goods*>(selectGood);
	ItemData data = good->GetItemData();

	// �ش� �̸��� �������� ã�´�
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
			// ��� �߰�
			gold += data.price >> 1;

			// ���� ����
			item->AddCount(-1);
			getItems[data.name]--;

			if (item->GetCount() <= 0)
			{
				// ������ ������ ����
				delete item;
				items.erase(items.begin() + i);
			}

			return;
		}
	}

	MessageBox(hWnd, L"�ش� �������� ã�� �� �����ϴ�.", L"Error", MB_OK);
}

void Player::OnSelectedItem(void* item)
{
	selectedItem = (InventoryItem*)item;
}

void Player::ShowHpBar(HDC hdc)
{
	string hpText = to_string(healthPoint);
	RECT textRect = { 100, 700, 50,50 };  // ���ʿ� ǥ��
	DrawTextA(hdc, hpText.c_str(), -1, &textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
