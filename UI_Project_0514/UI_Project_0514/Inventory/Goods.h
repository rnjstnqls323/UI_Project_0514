#pragma once

class Goods : public Button
{
private:
    Vector2 SIZE = { 200,100 };

public:
    Goods(Vector2 center, ItemData itemData);
    ~Goods();

    // 복사 생성자 추가
    Goods(const Goods& other);

    // 복사 대입 연산자 (필요하면)
    Goods& operator=(const Goods& other);

    void Render(HDC hdc);

    ItemData GetItemData() { return itemData; }
    void SetItemStatus(ItemStatus status) { itemData.status = status; }

    void SetCenter(Vector2 setCenter) { center = setCenter; }

    void ShowExplane(HDC hdc);

private:
    ItemData itemData;
};