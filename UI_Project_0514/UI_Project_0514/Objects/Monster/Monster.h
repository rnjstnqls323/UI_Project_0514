#pragma once
class Monster : public Singleton<Monster>, public Circle
{
	friend Singleton;

	// �÷��̾�� ������ ���� �� ����ֱ� ��� �����panel���� ������ ������ ����ձ�!
private:
	Monster();
	~Monster();

public:
	void Render(HDC hdc);
	void Update();

	void Die();
	void Fight();
private:
	int gold = 10;
	int healthPoint = 10;
	int attackPower = 5;

};