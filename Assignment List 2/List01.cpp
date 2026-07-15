#include <iostream>
#include <math.h>
using namespace std;

struct NODE{
    int data;
    NODE* next;
};
struct LIST{
    NODE* tail;
    NODE* pHead;
};
void CreateEmptyList(LIST & L){
    L.pHead=L.tail=NULL;
}
NODE* CreateNODE(int x){
    NODE*p=new NODE;
    if(p==NULL) exit(1);
    p->data=x;
    p->next=NULL;
    return p;
}
void Insert(LIST &L,int x){
    NODE*p=CreateNODE(x);
    if(L.pHead==NULL){
        L.pHead=L.tail=p;
    }
    else{
        L.tail->next=p;
        L.tail=p;
    }
}
void CreateList(LIST & L){
    int x;
    while(true){
        cin >> x;
        if(x==-1) break;
        Insert(L,x);
    }
}
bool isPrime(int x){
    if(x<2) return false;
    for(int i=2; i*i<=x; i++){
        if(x%i==0) return false;
    }
    return true;
}
int search_prime(NODE* p){
    int local=1;
    while(p!=NULL){
        if(isPrime(p->data)) return local;
        local++;
        p=p->next;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    cout << search_prime(L.pHead);

    return 0;
}
