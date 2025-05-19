#pragma once
#include "Manager/ItemDataManager.h"

class InventoryItem;
class ItemDataManager;
class Player : public Singleton<Player>, public Rect
{
	friend Singleton;

	// 플레이어는 아이템 정보 다 들고있기 노노 스토어panel에서 구매한 정보만 들고잇기!

private:
	const int MAX_HP = 1000;
private:
	Player();
	~Player();

public :
	void Render(HDC hdc);
	void Update();

	void AddItem(void* selectGood);
	void AddItem(ItemData data);

	void RemoveItem(void* selectGood);

	int GetGold() { return gold; }
	void SetGold(int gold) { this->gold = gold; }

	void OnSelectedItem(void* item);

	void NextStage() { stage++; }
	int GetStage() { return stage; }
	void SetStage(int stage) { this->stage = stage; }

	int GetHealthPoint() { return healthPoint; }
	void SetHealthPoint(int healthpoint) { this->healthPoint = healthpoint; }

	int GetAttackPower() { return attackPower; }
	void SetAttackPower(int attackPower) { this->attackPower = attackPower; }

	bool IsDie() { if (healthPoint <= 0) return true; else return false; }

	void ShowHpBar(HDC hdc);

	InventoryItem* GetEquipedItem() { return equipedItem; }

	vector<InventoryItem*> items;
private:
	int gold = 0;
	int stage = 1;
	int healthPoint = 1000;
	int attackPower = 0;

	InventoryItem* selectedItem = nullptr;
	InventoryItem* equipedItem = nullptr;
	
	unordered_map<string, int> getItems; // 이걸 이렇게 받을필요가 있을까?
};