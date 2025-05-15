#include "Framework.h"
#include "GameManager.h"

GameManager::GameManager()
{
	hdc = GetDC(hWnd);

	backBufferDC = CreateCompatibleDC(hdc);
	backBufferBitmap = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(backBufferDC, backBufferBitmap);

	SetBkMode(backBufferDC, TRANSPARENT);

	Create();

	//¾À »ý¼º ¹× Ãß°¡ ÀÌ°Ç ¾À¸¶´Ù ´Ù ÇØÁà¾ßµÉµí ("Å°°ª", new ¾À) ÀÌ·¸°Ô
	SCENE->AddScene("Title", new TitleScene());

	SCENE->ChangeScene("Title");
}

GameManager::~GameManager()
{
	ReleaseDC(hWnd, hdc);

	Release();

	DeleteObject(backBufferBitmap);
	DeleteDC(backBufferDC);
}

void GameManager::Update()
{
	Timer::Get()->Update();
	Input::Get()->Update();
	
	//¾À ¾÷µ¥ÀÌÆ®
	SCENE->Update();

	InvalidateRect(hWnd, nullptr, false);
}

void GameManager::Render()
{
	PatBlt(backBufferDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);

	//¾À ·»´õ
	SCENE->Render(backBufferDC);

	Timer::Get()->Render(backBufferDC);
	BitBlt(hdc,
		0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
		backBufferDC, 0, 0, SRCCOPY);
}

void GameManager::Create()
{
	Timer::Get();
	Input::Get();
	//¾À;
	SCENE;
}

void GameManager::Release()
{
	Timer::Delete();
	Input::Delete();

	//¾À»èÁ¦
	SCENE->Delete();
}
