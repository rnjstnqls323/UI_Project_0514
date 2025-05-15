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

void GoodsManager::Render(HDC hdc)
{
	for (Goods* good : goods)
	{
		good->Render(hdc);
	}
}

vector<Goods*> GoodsManager::GetInventoryGoods()
{
	vector<Goods*> result;
	for (Goods* good : goods)
	{
		if (good->GetItemData().status == ItemStatus::Inventory)
			result.push_back(good);
	}
	return result;
}

vector<Goods*> GoodsManager::GetStoreGoods()
{
	vector<Goods*> result;
	for (Goods* good : goods)
	{
		if (good->GetItemData().status == ItemStatus::Store)
			result.push_back(good);
	}
	return result;
}

vector<Goods*> GoodsManager::GetEquipGoods()
{
	vector<Goods*> result;
	for (Goods* good : goods)
	{
		if (good->GetItemData().status == ItemStatus::Equipped)
			result.push_back(good);
	}
	return result;
}
