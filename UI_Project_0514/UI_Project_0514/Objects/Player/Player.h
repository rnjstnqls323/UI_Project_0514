#pragma once

class Player : public Singleton<Player>
{
	friend Singleton;

	// �÷��̾�� ������ ���� �� ����ֱ� ��� �����panel���� ������ ������ ����ձ�!
private:
	Player();
	~Player();

public :
	void AddItem();
};