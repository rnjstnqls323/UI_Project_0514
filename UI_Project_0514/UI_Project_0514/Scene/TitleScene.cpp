#include "Framework.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{

	loadButton = new Button(Vector2(300, 200), Vector2(200, 100));
	loadButton->SetText(L"Load");
	loadButton->SetBrush(RGB(180, 255, 240), RGB(130, 220, 210), RGB(100, 190, 180));
	loadButton->SetEvent(bind(&TitleScene::OnClickLoad, this));

	startButton = new Button(Vector2(300, 400), Vector2(200, 100));
	startButton->SetText(L"Start");
	startButton->SetBrush(RGB(100, 255, 150), RGB(50, 200, 100), RGB(0, 150, 50));
	startButton->SetEvent(bind(&TitleScene::OnClickStart, this));



	exitButton = new Button(Vector2(300, 600), Vector2(200, 100));
	exitButton->SetBrush(RGB(255, 100, 150), RGB(200, 50, 100), RGB(150, 0, 50));
	exitButton->SetText(L"Exit");
	exitButton->SetEvent(bind(&TitleScene::OnClickExit, this));
}

TitleScene::~TitleScene()
{
	delete startButton;
	delete exitButton;
}

void TitleScene::Update()
{

	/*if (Input::Get()->IsKeyDown(VK_F1))
	{
		SCENE->ChangeScene("Inven");
	}*/
	loadButton->Update();
	startButton->Update();
	exitButton->Update();
}

void TitleScene::Render(HDC hdc)
{
	TextOut(hdc, 100, 100, L"Title Scene", 12);

	loadButton->Render(hdc);
	startButton->Render(hdc);
	exitButton->Render(hdc);
}

void TitleScene::OnClickStart()
{
	SCENE->ChangeScene("Inven");
}

void TitleScene::OnClickExit()
{
	PostQuitMessage(0);
}

void TitleScene::OnClickLoad()
{
	SCENE->ChangeScene("Load");
}
