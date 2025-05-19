#include "Framework.h"

InventoryItem::InventoryItem(Vector2 center, ItemData itemData)
	: Button(center, Vector2(100, 100)), itemData(itemData)
{
	SetBrush(RGB(255, 170, 170), RGB(255, 120, 120), RGB(240, 90, 90));

	selectedPen = CreatePen(PS_SOLID, 10, RGB(170, 255, 180));

	EventManager::Get()->AddEvent("ClickInvenItem",
		bind(&InventoryItem::OnSelectedItem, this, placeholders::_1));

	SetEvent(bind(&InventoryItem::OnClickItem, this));

	equipButton = new Button(Vector2::Zero(), Vector2(30, 30));
	equipButton->SetText(L"E");
	equipButton->SetBrush(RGB(180, 200, 220), RGB(150, 170, 190), RGB(120, 140, 160));
	equipButton->SetEvent(bind(&InventoryItem::OnClickEquip, this));

	unequipButton = new Button(Vector2::Zero(), Vector2(30, 30));
	unequipButton->SetText(L"X");
	unequipButton->SetBrush(RGB(180, 200, 220), RGB(150, 170, 190), RGB(120, 140, 160));
	unequipButton->SetEvent(bind(&InventoryItem::OnClickUnequip, this));
}

InventoryItem::~InventoryItem()
{
	DeleteObject(selectedPen);

	delete equipButton;
}

void InventoryItem::Update()
{
	Button::Update();

	if (isSelected)
	{
		if (itemData.equip)
		{
			unequipButton->SetCenter({ Right(), Bottom() });
			unequipButton->Update();
		}
		else
		{
			equipButton->SetCenter({ Left(), Bottom() });
			equipButton->Update();
		}
	}
}

void InventoryItem::Render(HDC hdc)
{
	if (isSelected)
		defaultPen = (HPEN)SelectObject(hdc, selectedPen);

	Button::Render(hdc);

	if (isSelected)
		SelectObject(hdc, defaultPen);

	string text = "Name : " + itemData.name;
	TextOutA(hdc, Left() + 10, Top() + 10, text.c_str(), text.length());
	text = "Value : " + to_string(itemData.value);
	TextOutA(hdc, Left() + 10, Top() + 30, text.c_str(), text.length());

	if (isSelected)
	{
		if (itemData.equip)
		{
			unequipButton->Render(hdc);
		}
		else
		{
			equipButton->Render(hdc);
		}
	}
}

void InventoryItem::OnSelectedItem(void* item)
{
	isSelected = (item == this);
}

void InventoryItem::OnClickItem()
{
	EventManager::Get()->ExcuteEvent("ClickInvenItem", this);
}

void InventoryItem::OnClickEquip()
{
	itemData.equip = true;
	Player::Get()->SetAttackPower(itemData.value);
	EventManager::Get()->ExcuteEvent("Equip", this);
}

void InventoryItem::OnClickUnequip()
{
	itemData.equip = false;
	Player::Get()->SetAttackPower(0);
	EventManager::Get()->ExcuteEvent("Unequip", this);
}
