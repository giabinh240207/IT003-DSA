#include <iostream>
using namespace std;
// code here
struct NODE{
    int data;
    NODE* next;
};
struct LIST{
    NODE* head;
    NODE* tail;
};
void CreateEmptyList(LIST &L){
    L.head=L.tail=NULL;
}
NODE* CreateNODE(int x){ //tao node
    NODE*p=new NODE;
    if(p==NULL)
        exit(1);
    p->data=x;
    p->next=NULL;
    return p;
}
void CreateList(LIST& L){ //them node vao dang sau
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
            p->next=L.head;  
            L.head=p;      
            //L.tail->next=p;
            //L.tail=p;
        }
    }
}

void PrintList(LIST L){
    NODE*p=L.head;
    if(L.head==NULL)
        cout << "Empty List.";
    while(p!=NULL){
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
