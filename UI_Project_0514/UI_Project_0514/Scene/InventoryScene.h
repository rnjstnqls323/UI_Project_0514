#pragma once
//private:
//const string FILE_PATH = "../DataFile/ItemData.csv" // �ε嵥�����ϱ� 

class InventoryScene : public Scene
{
private:
	enum class State
	{
		Store,
		Inventory,
		Equip,
		End,
	};

public:
	InventoryScene();
	~InventoryScene();

	void Update() override;
	void Render(HDC hdc) override;

	void Start() override {}
	void End() override {}

private:
	void CreateButtons();
	void CreatePanels();

	void OnClickButton(int index);

private:
	vector<Button*> buttons;
	vector<Panel*> panels;
};