#include <iostream>


struct POINT {
    int x; 
    int y; 
};

struct NODE {
    POINT data;
    NODE* next;
};

struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST& L) {
    L.pHead = L.pTail = NULL;
}


NODE* CreateNode(int x, int y) {
    NODE* newNode = new NODE;
    newNode->data.x = x;
    newNode->data.y = y;
    newNode->next = NULL;
    return newNode;
}


void AddTail(LIST& L, int x, int y) {
    NODE* newNode = CreateNode(x, y);
    if (L.pHead == NULL) {
        L.pHead = L.pTail = newNode;
    } else {
        L.pTail->next = newNode;
        L.pTail = newNode;
    }
}


void Nhap(LIST& L) {
    int n;
    if (!(std::cin >> n)) return;
    for (int i = 0; i < n; i++) {
        int hoanh, tung;
  
        std::cin >> tung >> hoanh;
        AddTail(L, hoanh, tung);
    }
}


void Xuat(LIST L) {
    if (L.pHead == NULL) return;
    NODE* p = L.pHead;
    while (p != NULL) {
        std::cout << "(" << p->data.y << ","<<" " << p->data.x << ")" << std::endl;
        p = p->next;
    }
}

int main() {
    LIST points;
    CreateEmptyList(points);
    Nhap(points);

    Xuat(points);

    return 0;
}
