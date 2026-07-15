#include <iostream>
using namespace std;
//code here

struct NODE{
    char data;
    NODE* next;
};
struct stack{
    NODE*top;
};
void CreateEmptyStack(stack &L){
    L.top=NULL;
}
NODE* CreateNODE(char x){
    NODE*p = new NODE();
    p->data=x;
    p->next=NULL;
    return p;
}
bool empty(stack L){
    return (L.top==NULL);
}
void push(stack &L, char x){
    NODE*p=CreateNODE(x);
    p->next=L.top;
    L.top=p;
}
void pop(stack&L){
    if(empty(L)) return;
    NODE*p=L.top;
    L.top=L.top->next;
    delete p;
}
char top(stack&L){
    if(empty(L)) exit(0);
    return L.top->data;
}
void BracketMatching(stack s, char st[]){
    CreateEmptyStack(s);
    cin.getline(st,100);
    for(int i=0;st[i]!='\0';i++){
        if(st[i]=='('){
            push(s,st[i]);
        }
        if(st[i]==')'){
            if(empty(s)){
                cout <<"False";
                return;
            }
            pop(s);
        }
    }
    if(empty(s)) cout <<"True";
    else cout << "False";
}

//
int main() {
    stack s;
    char st[100];
    BracketMatching(s,st);
    return 0;
}
