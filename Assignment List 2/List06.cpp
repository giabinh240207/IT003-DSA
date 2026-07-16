
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
void RemoveHead(LIST&L){
    if(L.head==nullptr) return;
    NODE*p=L.head;
    L.head=L.head->next;
    delete p;
}
void RemoveTail(LIST&L){
    if(L.head==nullptr) return;
    if(L.head==L.tail){
        delete L.head;
        L.head=L.tail=nullptr;
        return;
    }
    NODE*temp=L.head;
    while(temp->next!=L.tail){
        temp=temp->next;
    }
    NODE*p=L.tail;
    L.tail=temp;
    delete p;
    temp->next=nullptr;
}
void RemoveX(LIST&L,int x){
    if(L.head==nullptr) return;
    //neu x trung voi head 
    if(L.head->data==x){
        RemoveHead(L);
    }
    else{
        NODE*p=L.head;
        while(p->next){
            if(p->next->data==x){
                if(p->next==L.tail){
                    RemoveTail(L);
                    return;
                }
                NODE*q=p->next;
                p->next=q->next;
                delete q;
                return;
            }
            else p=p->next;
        }
    }
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

//
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
