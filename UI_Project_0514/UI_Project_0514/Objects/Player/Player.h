#pragma once

class Player : public Singleton<Player>
{
	friend Singleton;

	// 플레이어는 아이템 정보 다 들고있기 노노 스토어panel에서 구매한 정보만 들고잇기!
private:
	Player();
	~Player();

public :
	void AddItem();
};