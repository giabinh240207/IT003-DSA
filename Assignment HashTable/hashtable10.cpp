
#include <iostream>
using namespace std;
#define M 100

struct NODE {
    int key;
    NODE *pNext;
};
// Khai báo kiểu con trỏ chỉ node
typedef NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	p->key = x;
	p->pNext = NULL;
	return p;
}
void AddTail(NODE* &head, int x) {
	NODE *p=CreateNode(x);
    if (head == NULL) head = p;
	else {
        NODE* i=head;
        while(i->pNext!=NULL){
            i=i->pNext;
        }
        i->pNext=p;
    }
}

int HF(int numbucket, int key) { return key % numbucket; }

//code here
void InitHashTable(HASHTABLE &H, int numbucket){
    for(int i=0;i<numbucket;i++){
        H[i]=nullptr;
    }
}
void Insert(HASHTABLE &H,int numbucket,int x ){
    int index=HF(numbucket,x);
    AddTail(H[index],x);
}
void CreateHashTable(HASHTABLE &H, int& numbucket){
    cin>>numbucket;
    InitHashTable(H,numbucket);
    int x;
    while(true){
        cin >> x;
        if(x==-1) break;
        Insert(H,numbucket,x);
    }
}
void TraverseBucket(HASHTABLE H, int i){
    NODEPTR p=H[i];
    while(p){
        cout << "-->"<<" "<<p->key<<" ";
        p=p->pNext;
    }
}
void Traverse(HASHTABLE H, int numbucket){
    for(int i=0;i<numbucket;i++){
        cout << i <<" ";
        TraverseBucket(H,i);
        cout << endl;
    }
}
//

int main(){
    HASHTABLE H;
    int numbucket;

    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);

    return 0;
}
