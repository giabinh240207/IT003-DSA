
#include <iostream>
using namespace std;

struct NODE{
    int data;
    NODE*next;
};
struct LIST{
    NODE*tail;
    NODE*head;
};
void CreateEmptyList(LIST&L){
    L.head=L.tail=nullptr;
}
NODE*CreateNODE(int x){
    NODE *p=new NODE();
    if(p==nullptr) exit(1);
    p->data=x;
    p->next=nullptr;
    return p;
}
void Insert(LIST&L,int x){
    NODE*p=CreateNODE(x);
    if(L.head==nullptr){
        L.head=L.tail=p;
    }
    else{
        L.tail->next=p;
        L.tail=p;
    }
}
void CreateList(LIST&L){
    int x;
    while(true){
        cin>>x;
        if(x==-1) break;
        Insert(L,x);
    }
}

void RemoveX(LIST&L,int x){
    
}
void PrintList(LIST L){
    if(L.head==nullptr){
        cout <<"Empty List. ";
        return;
    }
    NODE*p=L.head;
    while(p!=nullptr){
        cout<<p->data<<" ";
        p=p->next;
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
