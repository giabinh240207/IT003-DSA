//Tong day theo danh sach chi so
#include <iostream>

using namespace std;
//code here
struct NODE{
    int data;
    NODE* next;
};
struct LIST{
    NODE*tail;
    NODE*head;
};

void CreateEmptyList(LIST &T){
    T.head=T.tail=nullptr;
}
NODE*CreateNODE(int x){
    NODE*p=new NODE;
    p->data=x;
    p->next=nullptr;
    return p;
}
void Insert(LIST &L, int x){
    NODE*p=CreateNODE(x);
    if(L.head==nullptr){
        L.head=p;
        L.tail=p;
    }
    else{
        L.tail->next=p;
        L.tail=p;
    }
}
void CreateList(LIST&L, int n){
    int x;
    for(int i=0;i<n;i++){
        cin >> x;
        Insert(L,x);
    }
}
int SumLocal(LIST L){
    int P;
    cin >> P;
    int count=0;
    for(int i=0;i<P;i++){
        int Local=0;
        int x;
        cin >> x;
        NODE*p=L.head;
        while(p){
            if(Local==x){
                count=count+p->data;
                break;
            }
            p=p->next;
            Local++;
        }
    }
    return count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LIST L;
    CreateEmptyList(L);
    int n;
    cin>>n;
    CreateList(L,n);
    cout << SumLocal(L);
    return 0;
}