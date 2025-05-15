#include "Framework.h"
#include "ItemDataManager.h"

ItemDataManager::ItemDataManager()
{
}

ItemDataManager::~ItemDataManager()
{
}

void ItemDataManager::LoadData(const string& fileName)
{
	ifstream file(fileName);
	if (!file.is_open())
	{
		MessageBox(nullptr, L"Failed to open file", L"Error", MB_OK);
		return;
	}

	string line;

	getline(file, line);
	while (getline(file, line))
	{
		vector<string> data = SplitData::SplitDatas(line, ",");

		ItemData itemData;
		itemData.key = stoi(data[0]);
		itemData.name = data[1];
		itemData.explane = data[2];
		itemData.price = stoi(data[3]);
		itemData.value = stoi(data[4]);
		itemData.status = ItemStatus::Store;

		itemDatas[itemData.key] = itemData;
	}
	file.close();
}
