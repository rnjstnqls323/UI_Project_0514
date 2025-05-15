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

	//void포인터 -> 어떤 타입인지 모를 때 사용
	void OnClickGood(void* good);
	void SetActive(bool active);


private:
	//vector<Goods*> goods;
	Goods* selectedGood = nullptr;
};