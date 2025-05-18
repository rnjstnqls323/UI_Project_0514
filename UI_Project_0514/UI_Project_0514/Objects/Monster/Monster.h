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

	void Die();
	void Fight();
private:
	int gold = 10;
	int healthPoint = 10;
	int attackPower = 5;

};