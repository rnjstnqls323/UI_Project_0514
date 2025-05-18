#pragma once
#include "Manager/ItemDataManager.h"

class InventoryItem;
class ItemDataManager;
class Player : public Singleton<Player>, public Rect
{
	friend Singleton;

	// �÷��̾�� ������ ���� �� ����ֱ� ��� �����panel���� ������ ������ ����ձ�!
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

	InventoryItem* GetEquipedItem() { return equipedItem; }

	vector<InventoryItem*> items;
private:
	int gold = 10000;
	int stage = 1;
	int healthPoint = 1000;
	int attackPower = 0;

	InventoryItem* selectedItem = nullptr;
	InventoryItem* equipedItem = nullptr;
	
	unordered_map<string, int> getItems; // �̰� �̷��� �����ʿ䰡 ������?
};