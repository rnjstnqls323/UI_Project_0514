#pragma once
//RGB(255, 240, 220)

class EquipPanel : public Panel
{
public:
	EquipPanel();
	~EquipPanel();

	void Update() override;
	void Render(HDC hdc) override;

private:
	void LoadGoods();

	void OnClickGood(void* good);

private:
	vector<Goods*> goods;
	Goods* selectedGood = nullptr;
};