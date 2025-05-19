#include "Framework.h"
#include "FightPanel.h"

FightPanel::FightPanel():Panel({400,550}, {400,200}, RGB(255, 240, 220))
{

}

FightPanel::~FightPanel()
{
}

void FightPanel::Render(HDC hdc)
{
	Panel::Render(hdc);
	DrawFightLogs(hdc);
}

void FightPanel::Update()
{
	Player::Get()->Update();
	Monster::Get()->Update();

	fightTimmer += DELTA;
	if (fightTimmer >= FIGHT_TIME)
	{
		Fight();
		fightTimmer = 0.0f;

	}
	if (fightTimmer >= CHANGE_SCENE_TIME && isEnd)
	{
		Monster::Get()->Reset();
		Player::Get()->SetStage(Player::Get()->GetStage() + 1);
		SCENE->ChangeScene("Inven");
	}
}

void FightPanel::AddFightLog(string message)
{
	fightLogs.push_back(message);

	if (fightLogs.size() > MAX_LINE) {
		fightLogs.erase(fightLogs.begin());  
	}
}

void FightPanel::DrawFightLogs(HDC hdc)
{
	int startX = 220;
	int startY = 500;
	int lineHeight = 40;

	for (int i = 0; i < fightLogs.size(); ++i) {
		RECT rect = { startX, startY + i * lineHeight, 500, startY + (i + 1) * lineHeight };
		DrawTextA(hdc, fightLogs[i].c_str(), -1, &rect, DT_LEFT | DT_TOP | DT_WORDBREAK);
	}
}

void FightPanel::Fight()
{
	Monster::Get()->SetHealthPoint(Monster::Get()->GetHealthPoint()-Player::Get()->GetAttackPower());
	text = "Player�� Monster�� �����Ͽ����ϴ�. \n" + to_string(Player::Get()->GetAttackPower()) + "�� �������� �������ϴ�!\n";
	AddFightLog(text);

	if (Monster::Get()->IsDie())
	{
		text = "Monster is Die!";
		AddFightLog(text);
		isEnd = true;
		Player::Get()->SetGold(Player::Get()->GetGold()+Monster::Get()->GetGold());
		return;
	}

	Player::Get()->SetHealthPoint(Player::Get()->GetHealthPoint() - Monster::Get()->GetHealthPoint());
	text = "Monster�� Player�� �����Ͽ����ϴ�. \n" + to_string(Monster::Get()->GetAttackPower()) + "�� �������� �������ϴ�!\n";
	AddFightLog(text);

	if (Player::Get()->IsDie())
	{
		text = "Player is Die!";
		AddFightLog(text);
		isEnd = true;
		return;
	}
}
