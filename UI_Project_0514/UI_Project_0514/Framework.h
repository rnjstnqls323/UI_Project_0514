#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

#define SCENE SceneManager::Get() 
#define CENTER Vector2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f)
#define PANEL_SIZE Vector2(400.0f,500.0f)

#define ITEM_PATH "DataFile/ItemData.csv"
#define PLAYER_SAVE_PATH "DataFile/SavePlayerInfo.csv"
#define INVEN_SAVE_PATH "DataFile/SaveInventoryInfo.csv"

#include <windows.h>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
#include <fstream>
#include <iostream>

using namespace std;

#include "Utility/Vector2.h"
#include "Utility/Singleton.h"
#include "Utility/Timer.h"
#include "Utility/Input.h"
#include "Utility/SplitData.h"

#define DELTA Timer::Get()->GetElapsedTime()

#include "Objects/Basic/GameObject.h"
#include "Objects/Basic/Circle.h"
#include "Objects/Basic/Rect.h"
#include "Objects/Player/Player.h" 
#include "Objects/Monster/Monster.h"

#include "Manager/ItemDataManager.h"
#include "Manager/PlayerDataManager.h"
#include "Manager/InvenDataManager.h"

#include "UI/Button.h"
#include "UI/Panel.h"

#include "Manager/EventManager.h"

#include "Inventory/Goods.h"
#include "Inventory/InventoryItem.h"


#include "Inventory/StorePanel.h"
#include "Inventory/InventoryPanel.h"
#include "Inventory/EquipPanel.h"
#include "Objects/Player/FightPanel.h"


#include "Scene/Scene.h"
#include "Scene/TitleScene.h"
#include "Scene/InventoryScene.h"
#include "Scene/SaveDataLoadScene.h"
#include "Scene/FightScene.h"

#include "Manager/SceneManager.h"
#include "Manager/GameManager.h"

extern HWND hWnd;
extern Vector2 mousePos;