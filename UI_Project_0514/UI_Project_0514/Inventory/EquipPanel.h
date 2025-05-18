#pragma once
//RGB(255, 240, 220)

class EquipPanel : public Panel
{
public:
	EquipPanel();
	~EquipPanel();

	void Update() override;
	void Render(HDC hdc) override;

	void OnEquipItem(void* equipsItem);
	void OnUnequipItem(void* equipsItem);

	void SetEquipItem(InventoryItem* equipItem) { this->equipItem = equipItem; }
private:
	InventoryItem* equipItem = nullptr;
};
