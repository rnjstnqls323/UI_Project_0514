#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

#define SCENE SceneManager::Get() 

#include <windows.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#include "Utility/Vector2.h"
#include "Utility/Singleton.h"
#include "Utility/Timer.h"

#include "Objects/Basic/GameObject.h"
#include "Objects/Basic/Circle.h"
#include "Objects/Basic/Rect.h"
#include "Scene/Scene.h"


#include "Manager/SceneManager.h"
#include "Manager/GameManager.h"

extern HWND hWnd;
extern Vector2 mousePos;