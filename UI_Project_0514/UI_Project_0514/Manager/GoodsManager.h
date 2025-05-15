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

private:
	vector<Goods*> goods;
};