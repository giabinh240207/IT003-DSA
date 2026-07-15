#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 100

struct NODE {
    char info;
    NODE *pNext;
};

struct stack {
    NODE* top;
};


void CreateEmptyStack(stack &L) {
    L.top = NULL;
}

NODE* CreateNODE(char x) {
    NODE* p = new NODE();
    if (p == NULL) exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

bool empty(stack p) {
    return (p.top == NULL);
}

void push(stack &L, char x) {
    NODE* p = CreateNODE(x);
    p->pNext = L.top;
    L.top = p;
}

void pop(stack &L) {
    if (empty(L)) return;
    NODE* p = L.top;
    L.top = L.top->pNext;
    delete p;
}

char top(stack L) {
    if (empty(L)) return '\0';
    return L.top->info;
}

// Hàm xác định độ ưu tiên toán tử
int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if(x=='^') return 3;
    return -1;
}


void Input_infix(char infix[], int &n) {
    char x;
    n = 0;
    while (cin >> x && x != '#') {
        infix[n++] = x;
    }
}

void infix_to_postfix(char infix[], int ni, char postfix[], int &np) {
    stack s;
    CreateEmptyStack(s);
    np = 0;

    for (int i = 0; i < ni; i++) {
        char c = infix[i];

        // 1. Nếu là chữ cái hoặc số: cho ra output
        if (isalnum(c)) {
            postfix[np++] = c;
        }
        // 2. Nếu là dấu mở ngoặc: push vào stack
        else if (c == '(') {
            push(s, c);
        }
        // 3. Nếu là dấu đóng ngoặc: pop stack ra output cho đến khi gặp '('
        else if (c == ')') {
            while (!empty(s) && top(s) != '(') {
                postfix[np++] = top(s);
                pop(s);
            }
            pop(s); // Xóa dấu '(' khỏi stack
        }
        // 4. Nếu là toán tử
        else {
            while (!empty(s) && priority(top(s)) >= priority(c)) {
                postfix[np++] = top(s);
                pop(s);
            }
            push(s, c);
        }
    }

    // Lấy nốt các toán tử còn lại trong stack
    while (!empty(s)) {
        postfix[np++] = top(s);
        pop(s);
    }
}

void Output(char postfix[], int np) {
    for (int i = 0; i < np; i++) {
        cout << postfix[i]<<" ";
    }
    cout << endl;
}

int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    // Nhập chuỗi kết thúc bằng dấu #. Ví dụ: a+b*(c-d)#
    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}