#pragma once

class FightScene : public Scene
{
private:
	const float LODING_TIME = 2.0f;

public:
	FightScene();
	~FightScene();

	void Update() override;
	void Render(HDC hdc) override;

	void Fight();

	void Start() override {}
	void End() override {}
private:
	float lodingTimmer = 0.0f;

	Panel* panel = nullptr;
};