#include "Framework.h"
#include "GoodsManager.h"

GoodsManager::GoodsManager()
{
	int itemCount = ItemDataManager::Get()->GetItemCount();
	//goods itemData�� itemdataManager�� �ϳ��ϳ� �����Ͱ� �־��ְ�, vector�� goods�����ϱ�
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
