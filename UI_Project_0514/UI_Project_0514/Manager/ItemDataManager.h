#pragma once



struct ItemData
{
	int key;
	string name;
	string explane;
	int price;
	int value;
	string status;
};

class ItemDataManager : public Singleton<ItemDataManager>
{
	friend class Singleton;


private:
	ItemDataManager();
	~ItemDataManager();

public:
	static void LoadData(const string& fileName);

	ItemData GetItem(int key) { return itemDatas[key]; }
	int GetItemCount() { return itemDatas.size(); }

private:
	unordered_map<int, ItemData> itemDatas;

};