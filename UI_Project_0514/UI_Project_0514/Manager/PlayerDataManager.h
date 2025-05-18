#pragma once
struct PlayerData
{
	int gold;
	int stage;
	int healthPoint;

};

class PlayerDataManager : public Singleton<PlayerDataManager>
{
	friend class Singleton;


private:
	PlayerDataManager();
	~PlayerDataManager();

public:
	void LoadData(const string& fileName);
	PlayerData GetPlayerData() { return playerData; }

private:
	PlayerData playerData;
};