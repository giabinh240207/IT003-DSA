#include <iostream>
using namespace std;

//code here
struct NODE{
    int data;
    NODE* next;
};
struct LIST{
    NODE* pHead;
    NODE* tail;
};
void CreateEmptyList(LIST& L){
    L.pHead=L.tail=NULL;
}
NODE * CreateNODE(int x){
    NODE*p=new NODE();
    p->data=x;
    p->next=NULL;
    return p;
}
void CreateList(LIST & L){
    int x;
    while(true){
        cin >> x ;
        if(x==-1) break;
        NODE*p=CreateNODE(x);
        if(L.pHead==NULL){
            L.pHead=L.tail=p;   
        }
        else{
            L.tail->next=p;
            L.tail=p;
        }
    }
}

void add_afterX_1(LIST& L,int Y,int X){
    NODE*p=L.pHead;
    while(p){
        if(p->data==X){
            NODE*q=CreateNODE(Y);
            q->next=p->next;
            p->next=q;
            if(L.tail==NULL)
                L.tail=q;
            p=q->next;
            break;
        }
        else p=p->next;
    }
}

void PrintList(NODE*p){
    if(p==NULL) cout << "Empty List.";
    while(p){
        cout << p->data << " ";
        p=p->next;
    }
}
//

int main() {
    LIST L;
	int X, Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> X >> Y;
	add_afterX_1(L, Y, X);

	PrintList(L.pHead);

    return 0;
}


