#pragma once

class FightPanel :public Panel
{
private:
	const int MAX_LINE = 3;
	const float FIGHT_TIME = 2.0f;
	const float CHANGE_SCENE_TIME = 1.0f;

public:
	FightPanel();
	~FightPanel();

	void Render(HDC hdc);
	void Update();

	void AddFightLog(string message);
	void DrawFightLogs(HDC hdc);

	void Fight();
	bool IsEnd() { return isEnd; }
private:
	bool isEnd = false;
	float fightTimmer = 0.0f;

	string text = "";

	vector<string> fightLogs;
};