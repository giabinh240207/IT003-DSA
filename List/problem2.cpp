#include <iostream>
#include <string>
#include <algorithm>

#include <iostream>

struct NODE {
    int data;
    NODE* next;
};

struct LIST {
    NODE* pHead;
    NODE* ptail;
};

void CreateEmptyList(LIST& L) {
    L.pHead = L.ptail = NULL;
}

NODE* CreateNode(int x) {
    NODE* newNode = new NODE;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void AddTail(LIST& L, int x) {
    NODE* newNode = CreateNode(x);
    if (L.pHead == NULL)
        L.pHead = L.ptail = newNode;
    else {
        L.ptail->next = newNode;
        L.ptail = newNode;
    }
}

void CreateList(LIST& L) {
    int x;
    while (true) {
        if (!(std::cin >> x) || x == -1) break;
        AddTail(L, x);
    }
}
void Function(NODE* head) {
    if (head == NULL) {
        std::cout << "Empty List.";
        return;
    }

    NODE* current = head;
    while (current != NULL) {
        int x = current->data;
        int y = -1; 

        NODE* search = current->next;
        while (search != NULL) {
            if (search->data > x) {
                y = search->data;
                break; 
            }
            search = search->next;
        }

        std::cout << x << " " << y << std::endl;
        current = current->next;
    }
}
int main() {
    LIST L;
	int X;
	CreateEmptyList(L);

	CreateList(L);

	Function(L.pHead);

    return 0;
}
