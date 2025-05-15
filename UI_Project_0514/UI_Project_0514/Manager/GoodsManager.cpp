#include "Framework.h"
#include "GoodsManager.h"

GoodsManager::GoodsManager()
{
	int itemCount = ItemDataManager::Get()->GetItemCount();
	//goods itemData에 itemdataManager로 하나하나 데이터값 넣어주고, vector로 goods관리하기
	for (int i = 0; i < itemCount; i++)
	{
		ItemData item = ItemDataManager::Get()->GetItem(1000 + i);
		goods.push_back(new Goods({ 0,0 }, item));
	}
	UpdateEquipList();
	UpdateInventoryList();
	UpdateStoreList();
}

GoodsManager::~GoodsManager()
{
	for (int i = 0; i < goods.size(); i++)
	{
		delete goods[i];
	}
}

void GoodsManager::Update()
{
	for (Goods* good : goods)
	{
		good->Update();
	}
}

void GoodsManager::UpdateInventoryList()
{
	inventoryGoods.clear();
	for (Goods* good : goods)
	{
		if (good->GetItemData().status == ItemStatus::Inventory)
			inventoryGoods.push_back(good);
	}
}

void GoodsManager::UpdateStoreList()
{
	storeGoods.clear();
	for (Goods* good : goods)
	{
		if (good->GetItemData().status == ItemStatus::Store)
			storeGoods.push_back(good);
	}
}

void GoodsManager::UpdateEquipList()
{
	equipGoods.clear();
	for (Goods* good : goods)
	{
		if (good->GetItemData().status == ItemStatus::Equipped)
			equipGoods.push_back(good);
	}
}

//void GoodsManager::Render(HDC hdc)
//{
//	for (Goods* good : goods)
//	{
//		good->Render(hdc);
//	}
//}

