#pragma once

class FightScene : public Scene
{
private:
	const float CHANGE_TIME = 2.0f;

public:
	FightScene();
	~FightScene();

	void Update() override;
	void Render(HDC hdc) override;

	void Start() override;
	void End() override;
private:
	float changeTimmer = 0.0f;

	FightPanel* panel = nullptr;
};