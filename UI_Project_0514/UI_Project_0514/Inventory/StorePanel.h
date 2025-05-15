#pragma once

class StorePanel : public Panel
{
public:
	StorePanel();
	~StorePanel();

	void Update() override;
	void Render(HDC hdc) override;

private:
	void LoadGoods();

	//void������ -> � Ÿ������ �� �� ���
	void OnClickGood(void* good);
	void SetActive(bool active);


private:
	//vector<Goods*> goods;
	Goods* selectedGood = nullptr;
};