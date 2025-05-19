#include "Framework.h"
#include "InventoryScene.h"

InventoryScene::InventoryScene()
{
	ItemDataManager::Get()->LoadData(ITEM_PATH);


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

	string goldText = "Gold : " + to_string(Player::Get()->GetGold());
	TextOutA(hdc, 0, 50, goldText.c_str(), goldText.length());


}



void InventoryScene::CreateButtons()
{
	buttons.push_back(new Button(Vector2(100, 100), Vector2(100, 50)));
	buttons.push_back(new Button(Vector2(200, 100), Vector2(100, 50)));
	buttons.push_back(new Button(Vector2(300, 100), Vector2(100, 50)));
	buttons.push_back(new Button(Vector2(500, 50), Vector2(100, 50)));
	buttons.push_back(new Button(Vector2(500, 100), Vector2(100, 50)));
	buttons[(int)State::Store]->SetText(L"Store");
	buttons[(int)State::Inventory]->SetText(L"Inventory");
	buttons[(int)State::Equip]->SetText(L"Equip");
	buttons[(int)State::Save]->SetText(L"SaveData");
	buttons[(int)State::Game]->SetText(L"PlayGame");

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
	buttons[(int)State::Save]->SetBrush(
		RGB(170, 240, 210),
		RGB(150, 220, 190),
		RGB(130, 200, 170)
	);
	buttons[(int)State::Game]->SetBrush(
		RGB(255, 240, 180),
		RGB(245, 225, 160),
		RGB(230, 210, 140)
	);


	for (int i = 0; i < (int)State::Save; i++)
	{
		buttons[i]->SetIntEvent(bind(&InventoryScene::OnClickButton, this, placeholders::_1));
		buttons[i]->SetIntParameter(i);
	}
	buttons[(int)State::Save]->SetIntEvent(bind(&InventoryScene::OnClickSaveButton, this));
	buttons[(int)State::Game]->SetIntEvent(bind(&InventoryScene::OnClickGameButton, this));
}

void InventoryScene::CreatePanels()
{
	panels.push_back(new StorePanel());
	panels.push_back(new InventoryPanel());
	panels.push_back(new EquipPanel());

	for (Panel* panel : panels)
	{
		panel->SetActive(false);
	}
}

void InventoryScene::OnClickButton(int index)
{
	for (int i = 0; i < panels.size(); i++)
	{
		panels[i]->SetActive(i == index);
	}
}

void InventoryScene::OnClickSaveButton()
{
	MessageBox(hWnd, L"ClickSave", L"", MB_OK);
	ofstream playerFile("DataFile/SavePlayerInfo.csv");
	playerFile << Player::Get()->GetGold() << "," << Player::Get()->GetStage()<<","<<Player::Get()->GetHealthPoint();
	playerFile.close();

	ofstream invenFile("DataFile/SaveInventoryInfo.csv");
	for (InventoryItem* item : Player::Get()->items)
	{
		int key = item->GetItemData().key;
		bool equipStatus = item->GetEquiped();

		invenFile << key << "," << equipStatus<<endl;
	}
	invenFile.close();
}

void InventoryScene::OnClickGameButton()
{
	//SceneManager::ChangeScene("FightScene"); 
	
	SCENE->ChangeScene("Fight");
}
