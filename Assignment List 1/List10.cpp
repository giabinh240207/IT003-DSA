//code here
#include<iostream>
#include<math.h>
#include <vector>
#include<string.h>
using namespace std;

int Num(int n){
    int sum=0;
    while(n!=0){
        sum++;
        n=n/10;
    }
    return sum;
}
bool ArmstrongNum(int x){
    if(x==0) return false;
    int sum = 0;
    int n=x;
    while(n!=0){
        int rem= n%10;
        sum = sum+ pow(rem,Num(x));
        n=n/10;
    }
    if(sum==x) return true;
    return false;
}
struct NODE{
    int data;
    NODE*next;
};
struct LIST{
    NODE*pHead;
    NODE*tail;
};
void CreateEmptyList(LIST& L){
    L.pHead=L.tail=NULL;
}
NODE* CreateNODE(int x ){
    NODE*p=new NODE();
    if(p==NULL) exit(1);
    p->data=x;
    p->next=NULL;
    return p;
}
void CreateList(LIST& L){
    int x ;
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

string searchX(NODE*p , int x){
    if(p==NULL) return "false";
    while(p){
        if(p->data==x) return "true";
        p=p->next;
    }
    return "false";
}

//
int main() {
    LIST L;
	int X;
	CreateEmptyList(L);

	CreateList(L);
	std::cin >> X;
	cout << searchX(L.pHead, X);

    return 0;
}
