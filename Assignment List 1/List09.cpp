//code here
#include<iostream>
#include<math.h>
#include <vector>
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
    NODE*head;
    NODE*tail;
};
void CreateEmptyList(LIST& L){
    L.head=L.tail=NULL;
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
        if(L.head==NULL){
            L.head=L.tail=p;
        }
        else{
            L.tail->next=p;
            L.tail=p;
        }
    }
}
void  PrintList_Armstrong(LIST L){
    vector<int> num;
    
    NODE*p=L.head;
    if(p==NULL){
        cout << "Empty List.";
        return;
    }
    bool flas=true;
    while(p){
        if(ArmstrongNum(p->data)){
            num.push_back(p->data);
            flas=false;
        }
        p=p->next;
    }
    if(flas) cout << "Không có số armstrong trong mảng.";
    for(int i=num.size()-1;i>=0;i--){
        cout << num[i] << " ";
    }
}
//


int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList_Armstrong(L);

    return 0;
}
