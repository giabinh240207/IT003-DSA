//code here

#include <iostream>
using namespace std;

bool PrimeCheck(int x){
    if(x<2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

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
void PrintList_Prime(LIST L){
    NODE*p = L.pHead;
    if(p==NULL) {
        cout << "Empty List.";
        return;
    }
        bool flag=true;
    while(p){
        if(PrimeCheck(p->data)){
            cout << p->data << " ";
            flag=false;
        }
        p=p->next;
    }
    if(flag) cout << "Không có số nguyên tố trong mảng.";
}

//
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList_Prime(L);

    return 0;
}
