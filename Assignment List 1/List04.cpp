#include <iostream>
using namespace std;

//code here
struct NODE{
    int data;
    NODE* next;
};
struct LIST{
    NODE* head;
    NODE* tail;
};
bool checkPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
void CreateEmptyList(LIST& L){
    L.head=L.tail=NULL;
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
        if(L.head==NULL){
            L.head=L.tail=p;   
        }
        else{
            L.tail->next=p;
            L.tail=p;
        }
    }
}
void add_after_all_prime(LIST &L , int y){
    NODE*p=L.head;
  
    while(p){
        if(checkPrime(p->data)){
            NODE*q=CreateNODE(y);
            q->next=p->next;
            p->next=q;
            if(L.tail==NULL){
                L.tail=q;
            }
            p=q->next;
        }
        else p=p->next;
    }
}
void PrintList(LIST L){
    NODE *p=L.head;
    if(p==NULL) cout << "Empty List.";
    while(p){
        cout << p->data << " ";
        p=p->next;
    }
}
//

int main() {
    LIST L;
	int Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> Y;
	add_after_all_prime(L, Y);

	PrintList(L);

    return 0;
}
