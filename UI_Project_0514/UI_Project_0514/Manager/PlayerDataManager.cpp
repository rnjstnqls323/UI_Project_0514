#include "Framework.h"
#include "PlayerDataManager.h"

PlayerDataManager::PlayerDataManager()
{
}

PlayerDataManager::~PlayerDataManager()
{
}

void PlayerDataManager::LoadData(const string& fileName)
{
	ifstream file(fileName);
	if (!file.is_open())
	{
		MessageBox(nullptr, L"Failed to open file", L"Error", MB_OK);
		return;
	}

	string line;
	getline(file, line);
	vector<string> data = SplitData::SplitDatas(line, ",");

	playerData.gold = stoi(data[0]);
	playerData.stage = stoi(data[1]);
	playerData.healthPoint = stoi(data[2]);
	file.close();


}
