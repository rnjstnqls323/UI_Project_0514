#include "Framework.h"

FightScene::FightScene():changeTimmer(0.0f)
{
	panel = new FightPanel();
}

FightScene::~FightScene()
{
	delete panel;
}

void FightScene::Update()
{
	panel->Update();
	changeTimmer += DELTA;

	/*if (changeTimmer >= CHANGE_TIME && panel->IsEnd())
	{
		Monster::Get()->Reset();
		SCENE->ChangeScene("Inven");
		changeTimmer = 0.0f;
	}*/
}

void FightScene::Render(HDC hdc)
{
	Player::Get()->Render(hdc);
	Monster::Get()->Render(hdc);
	panel->Render(hdc);
}

void FightScene::Start()
{
	changeTimmer = 0.0f;               // Ÿ�̸� �ʱ�ȭ
	Monster::Get()->SettingStage(Player::Get()->GetStage());
	panel = new FightPanel();
}

void FightScene::End()
{
	Monster::Get()->Reset();// ���� ���� �ʱ�ȭ
	delete panel;
}

