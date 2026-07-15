#include <iostream>
#include <string>
#include <algorithm>

#include <iostream>

struct NODE {
    int data;
    NODE* next;
};

struct LIST {
    NODE* head;
    NODE* tail;
};

void CreateEmptyList(LIST& L) {
    L.head = L.tail = NULL;
}

// Hàm bổ trợ tạo Node để tránh lỗi khởi tạo
NODE* CreateNode(int x) {
    NODE* newNode = new NODE;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void AddTail(LIST& L, int x) {
    NODE* newNode = CreateNode(x);
    if (L.head == NULL)
        L.head = L.tail = newNode;
    else {
        L.tail->next = newNode;
        L.tail = newNode;
    }
}

void CreateList(LIST& L) {
    int x;
    while (true) {
        if (!(std::cin >> x) || x == -1) break;
        AddTail(L, x);
    }
}

void add_after_middle(LIST& L, int Y) {
    // Trường hợp danh sách rỗng
    if (L.head == NULL) {
        return;
    }

    NODE* slow = L.head;
    NODE* fast = L.head;

    // Tìm node giữa
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Chèn node mới
    NODE* newNode = CreateNode(Y);
    newNode->next = slow->next;
    slow->next = newNode;

    // Cập nhật tail nếu newNode trở thành node cuối
    if (newNode->next == NULL)
        L.tail = newNode;
}

void PrintList(LIST L) {
    if (L.head == NULL) {
        std::cout << "Empty List."; 
        return;
    }
    NODE* p = L.head;
    while (p != NULL) { 
        std::cout << p->data << " ";
        p = p->next;
    }
}

int main() {
    LIST L;
	int X, Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> Y;
	add_after_middle(L, Y);

	PrintList(L);

    return 0;
}
