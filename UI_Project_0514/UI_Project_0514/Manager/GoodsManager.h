#pragma once

class GoodsManager :public Singleton<GoodsManager>
{

	friend class Singleton;
private:
	const int ITEM_SIZE = 5;

private:
	GoodsManager();
	~GoodsManager();

public:
	void Update();
	//void Render(HDC hdc);
	void UpdateInventoryList();
	void UpdateStoreList();
	void UpdateEquipList();



	vector<Goods*> GetInventoryGoods() { return inventoryGoods; }
	vector<Goods*> GetStoreGoods() { return storeGoods; }
	vector<Goods*> GetEquipGoods() { return equipGoods; }
	

private:
	vector<Goods*> inventoryGoods;
	vector<Goods*> storeGoods;
	vector<Goods*> equipGoods;

	vector<Goods*> goods;
};