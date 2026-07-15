#include <iostream>
using namespace std;
// code here
#include<vector>
struct NODE{
    int data;
    NODE* next;
};
struct stack{
    NODE* top;
};
NODE* CreateNODE(int x){
    NODE*p=new NODE;
    p->data=x;
    p->next=NULL;
    return p;
}
void CreateEmptyStack(stack &L){
    L.top=NULL;
}
bool empty(stack L){
    return (L.top==NULL);
}
void push(stack&L,int x){
    NODE*p =CreateNODE(x);
    p->next=L.top;
    L.top=p;
}
void pop(stack &L){
    if(empty(L)) return;
    NODE*p=L.top;
    L.top=L.top->next;
    delete p;
}
int top(stack &L){
    if(empty(L)) exit(0);
    return L.top->data;
}
void Testing_Push_Pop_Top_Stack(stack &s){
    CreateEmptyStack(s);
    int x;
    vector<int>A;
    while(true){
        cin >> x ;
        if(x==-1) break;
        if(x!=0) push(s,x);
        else{
           if(!empty(s)){
                A.push_back(top(s));
                pop(s);
           }
        }
    }
    cout << "output: ";
    for(int i=0;i<A.size();i++){
        cout << A[i] << " ";
    }
    cout << '\n';
    cout <<"top: "<<top(s);
}

int main() {
    stack s;
	Testing_Push_Pop_Top_Stack(s);
    return 0;
}
