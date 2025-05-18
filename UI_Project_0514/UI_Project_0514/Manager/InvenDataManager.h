#pragma once
struct InvenItemData
{
	int key;
	bool equiped;
};

class InvenItemDataManager : public Singleton<InvenItemDataManager>
{
	friend class Singleton;


private:
	InvenItemDataManager();
	~InvenItemDataManager();

public:
	void LoadData(const string& fileName);
	
	InvenItemData GetItem(int num) { return itemDatas[num]; } // ���ڷ� ����
	int GetItemCount() { return itemDatas.size(); }

private:
	unordered_map<int, InvenItemData> itemDatas;

};