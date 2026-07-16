//Sap xet day so nguyen
#include <iostream>
using namespace std;
//code here
struct node{
    int data;
    node* next;
};
struct LIST{
    node*tail;
    node*head;
};

void CreateEmptyLIST(LIST& l ){
    l.tail=l.head=nullptr;
}
node*CreateNODE(int x){
    node*p=new node;
    p->data=x;
    p->next=nullptr;
    return p;
}
void Insert(LIST&l, int x){
    node*p=CreateNODE(x);
    if(l.head==nullptr) 
        l.head=l.tail=p;
    else{
        l.tail->next=p;
        l.tail=p;
    }
}
void CreateLIST(LIST &L, int n){
    int x;
    for(int i=0;i<n;i++){
        cin >> x;
        Insert(L,x);
    }
}
void Selection_Sort(LIST&L){
    if(L.head==nullptr) return;
    //----------
    for(node*start=L.head;start->next!=nullptr;start=start->next){
        node* max=start;
        for(node*curr=start->next;curr!=nullptr;curr=curr->next){
            if(max->data<curr->data) max=curr;
        }
        swap(max->data,start->data);
    }
}
int Sum(LIST L){
    Selection_Sort(L);
    int local=0;
    int count=0;
    node*p=L.head;
    while(p){
       if(local%2==0) count=count+p->data;
       p=p->next;
       local++; 
    }
    return count;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LIST L;
    CreateEmptyLIST(L);
    int n; //so lung phan tu 
    cin>>n;
    CreateLIST(L,n);
    cout << Sum(L);
    return 0;
}