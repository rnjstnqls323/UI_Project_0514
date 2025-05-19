#include "Framework.h"

EquipPanel::EquipPanel() :Panel(CENTER, PANEL_SIZE, RGB(255, 240, 220))
{
	EventManager::Get()->AddEvent("Equip",
		bind(&EquipPanel::OnEquipItem, this, placeholders::_1));
	EventManager::Get()->AddEvent("Unequip",
		bind(&EquipPanel::OnUnequipItem, this, placeholders::_1));


}

EquipPanel::~EquipPanel()
{
}

void EquipPanel::Update()
{
	if (!isActive) return;

	Panel::Update();


	
	if (Player::Get()->GetEquipedItem()!=nullptr)
	{
		equipItem = Player::Get()->GetEquipedItem();
	}

	if (equipItem != nullptr)
	{
		Player::Get()->SetAttackPower(equipItem->GetItemData().value);
	}

}

void EquipPanel::Render(HDC hdc)
{
	if (!isActive) return;

	Panel::Render(hdc);

	Vector2 pos(Left() + 50, Top() + 50);


	string text;
	RECT rect = { pos.x, pos.y, pos.x + 300, pos.y + 1000 };


	if (equipItem != nullptr)
	{
		text = "장착 아이템 : " + equipItem->GetItemData().name + "\n아이템 설명 : " + equipItem->GetItemData().explane;
		Player::Get()->SetAttackPower(equipItem->GetItemData().value);
	}
	else
	{
		text = "장착 아이템 : 없음";
		Player::Get()->SetAttackPower(0);
	}
	DrawTextA(hdc, text.c_str(), -1, &rect, DT_WORDBREAK);
}

void EquipPanel::OnEquipItem(void* equipsItem)
{

	if (equipItem != nullptr)
	{
		equipItem->Unequip();
	}

	equipItem = (InventoryItem*)equipsItem;

}

void EquipPanel::OnUnequipItem(void* equipsItem)
{
	equipItem = nullptr;

}
