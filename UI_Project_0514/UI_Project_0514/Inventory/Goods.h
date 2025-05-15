#pragma once

class Goods : public Button
{
private:
	Vector2 SIZE = { 200,100 };
public:
	Goods(Vector2 center, ItemData itemData);
	~Goods();

	void Render(HDC hdc);

	ItemData GetItemData() { return itemData; }
	void SetItemStatus(string status) { itemData.status = status; }

private:
	ItemData itemData;
};