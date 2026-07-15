#include<iostream>
using namespace std;
//code here
struct NODE{
    int data;
    NODE* next;
};
struct LIST{
    NODE * head;
    NODE * tail;
};
void CreateEmptyList(LIST& L){
    L.head=L.tail=NULL;
}
NODE* CreateNODE(int x){
    NODE * p = new NODE();
    if(p==NULL)
        exit(1);
    p->data=x;
    p->next=NULL;
    return p;
}
void CreateList(LIST & L){
    int key, value;
    while(true){
        cin >> key >> value;
        if(key == -1 ) break;
        NODE*p=CreateNODE(value);
        if(L.head==NULL){
            L.head=p;
            L.tail=L.head;
        }
        else if(key==0){
            p->next=L.head;
            L.head=p;
        }
        else if(key==1){
            L.tail->next=p;
            L.tail=p;
        }
    }
}
void PrintList(LIST L){
    NODE*p=L.head;
    if(p==NULL) cout << "Empty List.";
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
    PrintList(L);

    return 0;
}
