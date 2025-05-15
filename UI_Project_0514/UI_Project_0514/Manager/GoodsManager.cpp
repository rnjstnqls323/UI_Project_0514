#include "Framework.h"
#include "GoodsManager.h"

GoodsManager::GoodsManager()
{
	int itemCount = ItemDataManager::Get()->GetItemCount();
	//goods itemData에 itemdataManager로 하나하나 데이터값 넣어주고, vector로 goods관리하기
	for (int i = 0;i < itemCount;i++)
	{
		ItemData item = ItemDataManager::Get()->GetItem(1000 + i);
		goods[i]->item
	}
}

GoodsManager::~GoodsManager()
{
}

void GoodsManager::Update()
{
}

void GoodsManager::Render(HDC hdc)
{
}
