//code here
#include<iostream>
using namespace std;

struct NODE{
    int data;
    NODE*next;
};
struct LIST{
    NODE*head;
    NODE*tail;
};

void CreateEmptyList(LIST&L){
    L.head=L.tail=NULL;
}
NODE* CreateNODE(int x){
    NODE*p = new NODE();
    if(p==NULL) exit(1);
    p->data=x;
    p->next=NULL;
    return p;
}
void CreateList(LIST &L){
    int x;
    while(true){
        cin >> x;
        if(x==-1) break;
        NODE*p=CreateNODE(x);
        if(L.head==NULL){
            L.head=p;
            L.tail=L.head;
        }
        else {
            L.tail->next=p;
            L.tail=p;
        }
    }
}
void add_after_k_th(LIST& L,int Y,int k){
    NODE*p=L.head;
    int size=1;
    while(p){
        if(size==k){
            NODE*q=CreateNODE(Y);
            q->next=p->next;
            p->next=q;
            if(L.tail==NULL) L.tail=q;
            break;
        }
        p=p->next;
        size++;

    }
}

void PrintList(LIST L){
    NODE*p=L.head;
    if(p==NULL)
        cout << "Empty List.";
    while(p){
        cout << p->data<<" ";
        p=p->next;
    }
}
//

int main() {
    LIST L;
	int k, Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> k >> Y;
	add_after_k_th(L, Y, k);

	PrintList(L);

    return 0;
}
