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

	bool IsDie();
	void Fight();

	void SettingStage(int stage) { 
		gold = stage * gold;
		healthPoint = stage * healthPoint;
		attackPower = stage * attackPower;
	}

	void Reset() {
		gold = 10;
		healthPoint = 10;
		attackPower = 5;
	}

	void SetHealthPoint(int healthPoint) { this->healthPoint = healthPoint; }
	int GetHealthPoint() { return healthPoint; }

	int GetGold() { return gold; }
	int GetAttackPower() { return attackPower; }

	void ShowBar(HDC hdc);
private:
	int gold = 10;
	int healthPoint = 30;
	int attackPower = 5;

};