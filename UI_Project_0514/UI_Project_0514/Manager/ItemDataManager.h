#pragma once


enum class ItemStatus
{
	Inventory,
	Store,
	Equipped
};

struct ItemData
{
	int key;
	string name;
	string explane;
	int price;
	int value;
	ItemStatus status;
};

class ItemDataManager : public Singleton<ItemDataManager>
{
	friend class Singleton;


private:
	ItemDataManager();
	~ItemDataManager();

public:
	void LoadData(const string& fileName);

	ItemData GetItem(int key) { return itemDatas[key]; }
	int GetItemCount() { return itemDatas.size(); }

private:
	unordered_map<int, ItemData> itemDatas;

};