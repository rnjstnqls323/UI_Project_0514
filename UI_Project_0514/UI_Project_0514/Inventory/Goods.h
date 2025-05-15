#pragma once

class Goods : public Button //아이템 정보 넣어서 버튼으로 만든거
{
private:
	Vector2 SIZE = { 200,100 };
public:
	Goods(Vector2 center, ItemData itemData);
	~Goods();

	void Render(HDC hdc);

	ItemData GetItemData() { return itemData; }
	void SetItemStatus(ItemStatus status) { itemData.status = status; }

	void SetCenter(Vector2 setCenter) { center = setCenter; }

private:
	ItemData itemData;
};