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

int length(LIST L){
    NODE*p=L.head;
    int count=0;
    while(p!=nullptr){
        count++;
        p=p->next;
    }
    return count;
}
//
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LIST L;
	CreateEmptyList(L);

	CreateList(L);

    cout << length(L);

    return 0;
}