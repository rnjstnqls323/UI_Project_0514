#pragma once

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();

	void Update() override;
	void Render(HDC hdc) override;

	void OnClickStart();
	void OnClickExit();
	void OnClickLoad();

private:
	Button* loadButton;
	Button* startButton;
	Button* exitButton;
};