#pragma once
class Monster : public Singleton<Monster>, public Circle
{
	friend Singleton;

	// 플레이어는 아이템 정보 다 들고있기 노노 스토어panel에서 구매한 정보만 들고잇기!
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