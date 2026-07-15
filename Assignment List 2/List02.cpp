#include <iostream>
using namespace std;

//code here
struct NODE{
    int data;
    NODE*next;
};

struct LIST{
    NODE*pTail;
    NODE*pHead;
};

void CreateEmptyList(LIST&L){
    L.pHead=L.pTail=NULL;
}
NODE*CreateNODE(int x){
    NODE * p= new NODE;
    if(p==NULL) exit(1);
    p->data=x;
    p->next=NULL;
    return p;
}
void Insert(LIST & L, int x){
    NODE*p=CreateNODE(x);
    if(L.pHead==NULL){
        L.pHead=p;
        L.pTail=p;
    }
    else{
        L.pTail->next=p;
        L.pTail=p;
    }
}
void CreateList(LIST & L){
    int x;
    while(true){
        cin>>x;
        if(x==-1) break;
        Insert(L,x);
    }
}

int count_even(NODE*p){
    int count=0;
    while(p!=NULL){
        if(p->data%2==0) count++;
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
    cout << count_even(L.pHead);

    return 0;
}
