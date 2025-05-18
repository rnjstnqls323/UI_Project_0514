#pragma once

class Goods : public Button
{
private:
    Vector2 SIZE = { 200,100 };

public:
    Goods(Vector2 center, ItemData itemData);
    Goods(Vector2 center,Vector2 size, ItemData itemData);
    ~Goods();

    // ���� ������ �߰�
    Goods(const Goods& other);

    // ���� ���� ������ (�ʿ��ϸ�)
    Goods& operator=(const Goods& other);

    void Render(HDC hdc);

    ItemData GetItemData() { return itemData; }

    void SetCenter(Vector2 setCenter) { center = setCenter; }

    void ShowExplane(HDC hdc);

    bool IsEquiped() { return isEquiped; }
    void SetEquip(bool isEquiped) { this->isEquiped = isEquiped; }

private:
    ItemData itemData;
    bool isEquiped = false;
};