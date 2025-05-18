#include "Framework.h"
#include "SaveDataLoadScene.h"

SaveDataLoadScene::SaveDataLoadScene()
{
	PlayerDataManager::Get()->LoadData(PLAYER_SAVE_PATH);
	InvenItemDataManager::Get()->LoadData(INVEN_SAVE_PATH);


}

SaveDataLoadScene::~SaveDataLoadScene()
{
}

void SaveDataLoadScene::Update()
{
	lodingTimmer += DELTA;
	if (lodingTimmer >= LODING_TIME)
	{
		LoadingData();
		SCENE->ChangeScene("Inven");
	}

}

void SaveDataLoadScene::Render(HDC hdc)
{
	RECT rect = { CENTER.x, CENTER.y, CENTER.x + 300, CENTER.y + 1000 };

	string text = "데이터 로딩중입니다.\n잠시만 기다려주세요";

	DrawTextA(hdc, text.c_str(), -1, &rect, DT_WORDBREAK);
}

void SaveDataLoadScene::LoadingData()
{
	PlayerData playerData = PlayerDataManager::Get()->GetPlayerData();
	int invenNum = InvenItemDataManager::Get()->GetItemCount();

	for (int i = 0; i < invenNum; i++)
	{
		InvenItemData saveData = InvenItemDataManager::Get()->GetItem(i);
		ItemData data = ItemDataManager::Get()->GetItem(saveData.key);

		if (saveData.equiped)
		{
			data.equip = true;
		}

		Player::Get()->AddItem(data);
	}

	Player::Get()->SetGold(playerData.gold);
	Player::Get()->SetStage(playerData.stage);
	Player::Get()->SetHealthPoint(playerData.healthPoint);


}
