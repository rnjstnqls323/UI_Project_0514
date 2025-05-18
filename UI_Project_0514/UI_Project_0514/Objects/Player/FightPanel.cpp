#include "Framework.h"
#include "FightPanel.h"

FightPanel::FightPanel():Panel({400,550}, {400,200}, RGB(255, 240, 220))
{

}

FightPanel::~FightPanel()
{
}

void FightPanel::Render(HDC hdc)
{
	Panel::Render(hdc);
}

void FightPanel::Update()
{
}

void FightPanel::DrawText()
{
}
