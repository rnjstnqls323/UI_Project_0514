#pragma once
//RGB(210, 255, 210)

class InventoryPanel : public Panel
{
public :
	InventoryPanel();
	~InventoryPanel();

	void Update() override;
	void Render(HDC hdc) override;
	void SetActive(bool active);

private:
	void LoadGoods();

	void OnClickGood(void* good);

private:
	vector<Goods*> goods;
	vector<Goods*> inventoryGoods;
	Goods* selectedGood = nullptr;
};