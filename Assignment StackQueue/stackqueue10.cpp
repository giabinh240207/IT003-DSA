#include <iostream>
using namespace std;

struct NODE{
    char info;
    NODE *pNext;
};
struct queue{
    NODE *front;
    NODE *back;
};
NODE *CreatNode(int x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;

//code here
}
#include <string>

NODE *CreatcharNode(char x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
}

void createEmptyQUEUE(queue& L){
    L.front=L.back=NULL;
}
bool isEmpty(queue L){
    return(L.front==NULL);
}
void enQueue(queue& L, NODE *p){
    if(isEmpty(L)){
        L.back=L.front=p;
    }
    else{
        L.back->pNext=p;
        L.back=p;
    }
}
void deQueue(queue& L){
    if(isEmpty(L)) return;
    NODE *p=L.front;
    L.front=p->pNext;
    delete p;
}
char front(queue L){
    if(isEmpty(L)) exit(1);
    return L.front->info;
}
char back(queue L){
    if(isEmpty(L)) exit(1);
    return L.back->info;
}
void createQueue(queue& L){
    createEmptyQUEUE(L);
    string t;
    getline(cin,t);
    for(int i = 0; i < t.size(); i++){
		t[i] = tolower(t[i]);
	}
    bool flas=true;
    if(t.empty()){
        cout << "Empty";
        return;
    }
    for(int i=0;i<t.size();i++){
        enQueue(L,CreatcharNode(t[i]));
    }
    for(int i=t.size()-1;i>=0;i--){
        if(front(L)!=t[i]){
            flas =false;
            break;
        }
        deQueue(L);
    }
    if(flas) cout <<"True";
    else cout << "False";
}

//
int main() {
    queue q;
	createQueue(q);
    return 0;
}
