#include <iostream>

struct NODE {
    int data;
    NODE* next;
};

struct LIST {
    NODE* phead;
    NODE* ptail;
};

void CreateEmptyList(LIST& L) {
    L.phead = L.ptail = NULL;
}

NODE* CreateNode(int x) {
    NODE* newNode = new NODE;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void AddTail(LIST& L, int x) {
    NODE* newNode = CreateNode(x);
    if (L.phead == NULL) {
        L.phead = L.ptail = newNode;
    } else {
        L.ptail->next = newNode;
        L.ptail = newNode;
    }
}

void CreateList(LIST& L) {
    int x;
    while (std::cin >> x && x != -1) {
        AddTail(L, x);
    }
}

void RemoveX(LIST& L, int X) {
    if (L.phead == NULL) return;

    NODE* curr = L.phead;
    NODE* prev = NULL;

    while (curr != NULL && curr->data != X) {
        prev = curr;
        curr = curr->next;
    }


    if (curr != NULL) {
    
        if (prev == NULL) {
            L.phead = curr->next;
            if (L.phead == NULL) L.ptail = NULL; 
        } 
        else {
            prev->next = curr->next;
            if (curr == L.ptail) {
                L.ptail = prev;
            }
        }
        delete curr; 
    }
}

void PrintList(LIST L) {
    if (L.phead == NULL) {
        std::cout << "Empty List.";
        return;
    }
    NODE* p = L.phead;
    while (p != NULL) {
        std::cout << p->data << (p->next != NULL ? " " : "");
        p = p->next;
    }
}


int main() {
    LIST L;
	int X;
	CreateEmptyList(L);

	CreateList(L);
	std::cin >> X;
	RemoveX(L, X);
    PrintList(L);

    return 0;
}
