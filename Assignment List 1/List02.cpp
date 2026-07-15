#include <iostream>
using namespace std;
// code here
struct NODE{
    int data;
    NODE * next;
};
struct LIST{
    NODE * pHead;
    NODE * tail;
};
void CreateEmptyList(LIST& L){
    L.pHead=L.tail=NULL;
}
NODE* CreateNODE(int x){
    NODE* p = new NODE();
    if(p==NULL)
        exit(1);
    p->data=x;
    p->next=NULL;
    return p;
}
void CreateList(LIST &L){
    int x;
    while(true){
        cin >> x ;
        if(x==-1) break;
        NODE * p = CreateNODE(x);
        if(L.pHead==NULL){
            L.pHead=p;
            L.tail=L.pHead;
        }
        else{
            L.tail->next=p;
            L.tail=p;
        }
    }
}
void PrintList(NODE*p){
    if(p==NULL) 
        cout << "Empty List.";
    while(p){
        cout << p->data << " ";
        p=p->next;
    }
}

//
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList(L.pHead);

    return 0;
}
