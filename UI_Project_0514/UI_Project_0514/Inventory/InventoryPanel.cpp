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

	for (Goods* good : GoodsManager::Get()->GetInventoryGoods()) //�ߺ�ȣ��Ǵµ�
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
			break; // �ϳ��� �׷�
		}
	}
}

void InventoryPanel::SetActive(bool active)
{
	Panel::SetActive(active);

	if (active)
	{
		LoadGoods(); // ���⿡ �ٽ� ���ε� ����� ��!
	}
}

void InventoryPanel::LoadGoods()
{
	//goods = GoodsManager::Get()->GetInventoryGoods();

	for (Goods* good : GoodsManager::Get()->GetInventoryGoods())
	{
		Goods* copyGood = new Goods(*good);  // ���� ������ ȣ��
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

	// ������ ��� ������ ����
	vector<Goods*> equip = GoodsManager::Get()->GetEquipGoods();
	for (Goods* good : equip)
	{
		good->SetItemStatus(ItemStatus::Inventory);
	}

	// ������ ������ ���� ���·� ����
	selectedGood->SetItemStatus(ItemStatus::Equipped);

	// ����Ʈ ������Ʈ
	GoodsManager::Get()->UpdateInventoryList();
	GoodsManager::Get()->UpdateEquipList();
}
