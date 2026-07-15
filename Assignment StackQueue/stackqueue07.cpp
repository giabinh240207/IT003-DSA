#include <iostream>
using namespace std;
//code here
struct NODE{
    int data;
    NODE * next;
};
struct stack{
    NODE* top;
};
void CreateEmptyStack(stack&L){
    L.top=NULL;
}
NODE* CreateNODE(int x){
    NODE*p=new NODE();
    p->data=x;
    p->next=NULL;
    return p;
}
bool empty(stack L){
    return(L.top==NULL);
}
void push(stack &L, int x){
    NODE*p=CreateNODE(x);
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
void array_reverse(stack s, int a[], int n){
    CreateEmptyStack(s);
    cin >> n;
    int x;
    for(int i=0;i<n;i++){
        cin >> x;
        push(s,x);
    }
    for(int i=0;i<n;i++){
        a[i]=top(s);
        pop(s);
    }
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}

//
int main() {
    stack s;
    int a[100], n;
    array_reverse(s,a,n);
    return 0;
}
