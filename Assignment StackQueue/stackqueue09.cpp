#include <iostream>
using namespace std;

struct NODE{
    int info;
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
}
//code here
#include <vector>

void createEmptyQueue(queue& L){
    L.back=L.front=NULL;
}
bool isEmpty(queue& L){
    if(L.front==NULL){
        return true;
    }
    return false;
}
void enQueue(queue& L, NODE*p){
    if(L.front==NULL){
        L.front=L.back=p;
    }
    else{
        L.back->pNext=p;
        L.back=p;
    }
}
void deQueue(queue& L){
    if(L.front==NULL) return;
    NODE *p=L.front;
    L.front=p->pNext;
    delete p;
}
int front(queue& L){
    if(L.front==NULL) exit(1);
    return L.front->info;
}
int back(queue& L){
    if(L.front==NULL) exit(1);
    return L.back->info;
}
void createQueue(queue&L){
    createEmptyQueue(L);
    int x;
    vector<int> data;
    while(true){
        cin >> x;
        if(x==-1) break;
        if(x!=0){
            enQueue(L,CreatNode(x));
        }
        if(x==0&&!isEmpty(L)){
            data.push_back(front(L));
            deQueue(L);
        }
    }
    cout <<"output: ";
    for(int i=0;i<data.size();i++){
        cout << data[i] <<" ";
    }
    cout << '\n';
    if(!isEmpty(L)){
        cout << "front: " << front(L); cout << '\n';
        cout << "back: " << back(L);
    }
    else{
        cout << "front: "; cout << '\n';
        cout << "back: ";
    }
}
//
int main() {
    queue q;
	createQueue(q);
    return 0;
}
