


#include <iostream>
using namespace std;
#define LOAD 0.7

struct Node {
    int key;
    Node* next;
};
struct List {
    Node* head;
    Node* tail;
};

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};

Node* CreateNode(int x) {
	Node* p = new Node;
	p->key = x;
	p->next = NULL;
	return p;
}

void AddTail(List &l, int x) {
	Node *p=CreateNode(x);
    if (l.head == NULL) {
        l.head = p;
        l.tail = p;
    }
	else {
        l.tail->next=p;
        l.tail=p;
    }
}
 
void CreateEmptyList(List &l) {
    l.head = NULL;
    l.tail = NULL;
}

void CreateEmptyHashtable(Hashtable &ht, int &m) {
    cin>>m;
    ht.table = new List[m];
    for (int i = 0; i < m; i++)
        CreateEmptyList(ht.table[i]);
    ht.M = m;
    ht.n = 0;
}

int HF(int key, int M) {
    return key%M;
}
  

//code here
void CreateEmptyList(List&L){
    L.tail=L.head=nullptr;
}
void InputHashtable(Hashtable&H){
    int x ;
    while(true){
        cin >> x;
        if(x==-1) break;
        int i=HF(x,H.M);
        AddTail(H.table[i].head,x);
        H.n++;
    }
}

void OutputHashtable(Hashtable H){
    
}


//


int main(){
    Hashtable H;
    int M,x;
    CreateEmptyHashtable(H, M);
    InputHashtable(H); 
    OutputHashtable(H); 
    return 0;
}
 
