#include "Framework.h"

FightScene::FightScene()
{
	panel = new FightPanel();
}

FightScene::~FightScene()
{
}

void FightScene::Update()
{
}

void FightScene::Render(HDC hdc)
{
	Player::Get()->Render(hdc);
	Monster::Get()->Render(hdc);
	panel->Render(hdc);
}

void FightScene::Fight()
{
}
