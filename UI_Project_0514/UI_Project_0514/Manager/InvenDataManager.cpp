#include "Framework.h"
#include "InvenDataManager.h"

InvenItemDataManager::InvenItemDataManager()
{
}

InvenItemDataManager::~InvenItemDataManager()
{
}

void InvenItemDataManager::LoadData(const string& fileName)
{
	ifstream file(fileName);
	if (!file.is_open())
	{
		MessageBox(nullptr, L"Failed to open file", L"Error", MB_OK);
		return;
	}

	int count = 0;
	string line;
	while (getline(file, line))
	{
		vector<string> data = SplitData::SplitDatas(line, ",");

		InvenItemData itemData;
		itemData.key = stoi(data[0]);
		itemData.equiped = stoi(data[1]);

		itemDatas[count++] = itemData;
	}
	file.close();
}
