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
	void Render(HDC hdc);
	Goods* GetGood(int index) { return goods[index]; }

	vector<Goods*> GetInventoryGoods();
	vector<Goods*> GetStoreGoods();
	vector<Goods*> GetEquipGoods();

private:
	vector<Goods*> goods;
};