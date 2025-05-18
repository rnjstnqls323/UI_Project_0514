#pragma once

class SaveDataLoadScene : public Scene
{
private:
	const float LODING_TIME = 2.0f;

public:
	SaveDataLoadScene();
	~SaveDataLoadScene();

	void Update() override;
	void Render(HDC hdc) override;

	void LoadingData();

	void Start() override {}
	void End() override {}
private:
	float lodingTimmer = 0.0f;
};