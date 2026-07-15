
#include <iostream>
#include <iomanip>
using namespace std;

struct NODE_CHAR{
    char info;
    NODE_CHAR *pNext;
};

struct stack{
    NODE_CHAR *top;
};
NODE_CHAR *CreateNode(float x){
    NODE_CHAR *p=new NODE_CHAR;
    p->info=x;
    p->pNext=NULL;
    return p;
}
//code here
void CreateEmptyStack(stack&L){
    L.top=NULL;
}
bool empty(stack &L){
    if(L.top==NULL) return true;
    return false;
}
void push(stack &L, char x){
    NODE_CHAR *p=CreateNode(x);
    p->pNext=L.top;
    L.top=p;
}
void pop(stack&L){
    if(empty(L)) return;
    NODE_CHAR*p=L.top;
    L.top=L.top->pNext;
    delete p;
}

char top(stack&L){
    if(empty(L)) return '\0';
    return L.top->info;
}
int priority(char x){
    if(x=='+'||x=='-') return 1;
    if (x=='*'||x=='/'||x=='%') return 2;
    if(x=='^') return 3;
    return -1;
}
bool checkOperator(char c){
    if(c=='+'||c=='/'||c=='-'||c=='*'||c=='^'||c=='%') return true;
    return false;
}
NODE_CHAR* input_infix(){
    char c1, c2;
    cin >> c1 >> c2;
    if (!(checkOperator(c1)&&checkOperator(c2))) return NULL;

    NODE_CHAR* head = CreateNode(c1);
    head->pNext = CreateNode(c2);
    return head;
}
NODE_CHAR* infix_to_postfix(NODE_CHAR* infix){
    if (infix == NULL || infix->pNext == NULL) return infix;

    stack s;
    CreateEmptyStack(s);

  
    push(s, infix->info);        
    push(s, infix->pNext->info); 


    char op2 = top(s); pop(s);
    char op1 = top(s); pop(s);

    int p1 = priority(op1);
    int p2 = priority(op2);

    char logic;
    if (p1 > p2) logic = '>';
    else if (p1 < p2) logic = '<';
    else logic = '=';


    NODE_CHAR* res = CreateNode(op1);
    res->pNext = CreateNode(logic);
    res->pNext->pNext = CreateNode(op2);

    return res;
}
void out(NODE_CHAR*p){
    if(p==NULL) return;
    cout << p->info << " " << p->pNext->info << " " << p->pNext->pNext->info;
}

//

int main() {
    NODE_CHAR *infix=NULL;
    NODE_CHAR *postfix;

    infix=input_infix();

    postfix=infix_to_postfix(infix);
    out(postfix);
    return 0;
}
