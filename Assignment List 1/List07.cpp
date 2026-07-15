//code here
#include <iostream>
using namespace std;


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
void PrintList_Odd(NODE*p){
    if(p==NULL) {
        cout << "Empty List.";
        return;
    }
        bool flag=true;
    while(p){
        if(p->data%2!=0){
            cout << p->data << " ";
            flag=false;
        }
        p=p->next;
    }
    if(flag) cout << "Không có số lẻ trong mảng.";
}

//
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList_Odd(L.pHead);

    return 0;
}
