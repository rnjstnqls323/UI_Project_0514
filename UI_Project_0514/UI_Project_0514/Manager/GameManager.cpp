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

	//�� ���� �� �߰� �̰� ������ �� ����ߵɵ� ("Ű��", new ��) �̷���

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
	
	//�� ������Ʈ
	SCENE->Update();

	InvalidateRect(hWnd, nullptr, false);
}

void GameManager::Render()
{
	PatBlt(backBufferDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);

	//�� ����
	SCENE->Render(hdc);

	Timer::Get()->Render(backBufferDC);
	BitBlt(hdc,
		0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
		backBufferDC, 0, 0, SRCCOPY);
}

void GameManager::Create()
{
	Timer::Get();

	//��;
	SCENE;
}

void GameManager::Release()
{
	Timer::Delete();

	//������
	SCENE->Delete();
}
