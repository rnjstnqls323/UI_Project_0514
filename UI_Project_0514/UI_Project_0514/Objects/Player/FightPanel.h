#pragma once

class FightPanel :public Panel
{
public:
	FightPanel();
	~FightPanel();

	void Render(HDC hdc);
	void Update();

	void DrawText();

	
};