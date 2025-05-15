#include "Framework.h"
#include "InventoryScene.h"

InventoryScene::InventoryScene()
{
	ItemDataManager::Get()->LoadData("../DataFile/ItemData.csv");
	GoodsManager::Get();

	CreateButtons();
	CreatePanels();
}

InventoryScene::~InventoryScene()
{
	for (Button* button : buttons)
	{
		delete button;
	}
	buttons.clear();
}

void InventoryScene::Update()
{
	for (Button* button : buttons)
		button->Update();

	for (Panel* panel : panels)
		panel->Update();
}

void InventoryScene::Render(HDC hdc)
{
	for (Button* button : buttons)
		button->Render(hdc);

	for (Panel* panel : panels)
		panel->Render(hdc);

}



void InventoryScene::CreateButtons()
{
	buttons.push_back(new Button(Vector2(100, 100), Vector2(100, 50)));
	buttons.push_back(new Button(Vector2(200, 100), Vector2(100, 50)));
	buttons.push_back(new Button(Vector2(300, 100), Vector2(100, 50)));
	buttons[(int)State::Store]->SetText(L"Store");
	buttons[(int)State::Inventory]->SetText(L"Inventory");
	buttons[(int)State::Equip]->SetText(L"Equip");

	buttons[(int)State::Store]->SetBrush(
		RGB(255, 230, 100),   // Normal (¹àÀº ±Ý»ö/²Ü»ö)
		RGB(245, 200, 80),    // Over
		RGB(230, 170, 60)     // Down
	);
	buttons[(int)State::Inventory]->SetBrush(
		RGB(180, 240, 255),   // Normal (¹àÀº ÇÏ´Ã¹ÎÆ®»ö)
		RGB(150, 220, 245),   // Over
		RGB(120, 200, 230)    // Down
	);
	buttons[(int)State::Equip]->SetBrush(
		RGB(220, 190, 255),   // Normal (¶óº¥´õ ´À³¦)
		RGB(200, 170, 240),   // Over
		RGB(180, 150, 220)    // Down
	);

	for (int i = 0; i < (int)State::End; i++)
	{
		buttons[i]->SetIntEvent(bind(&InventoryScene::OnClickButton, this, placeholders::_1));
		buttons[i]->SetIntParameter(i);
	}

	//buttons[0]->SetEvent([]() { /* Store button event */ });
	//buttons[1]->SetEvent([]() { /* Inventory button event */ });
	//buttons[2]->SetEvent([]() { /* Equip button event */ });
}

void InventoryScene::CreatePanels()
{
	panels.push_back(new StorePanel());
	panels.push_back(new Panel(CENTER, Vector2(400, 300), RGB(0, 0, 255)));
	panels.push_back(new Panel(CENTER, Vector2(400, 300), RGB(255, 0, 0)));

	for (Panel* panel : panels)
	{
		panel->SetActive(false);
	}
}

void InventoryScene::OnClickButton(int index)
{
	panels[index]->SetActive(true);
}