
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//code here
void CreateEmptyTree(TREE& T){
    T=NULL;
}
TREE createNODE(int x){
    TREE p;
    p=new TNODE;
    if(p==NULL) exit(1);
    p->key=x;
    p->pLeft=p->pRight=NULL;
    return p;
}
void Insert(TREE& T, int x){
    if(T==NULL){
        T=createNODE(x);
        return;
    }
    if(x<T->key){
        Insert(T->pLeft,x);
    }
    else if(x>T->key){
        Insert(T->pRight,x);
    }
}
void CreateTree(TREE& T){
    CreateEmptyTree(T);
    int x;
    while(true){
        cin >> x;
        if(x==-1) break;
        Insert(T,x);
    }
    if(T==NULL){
        cout<<"Empty Tree.";
        exit(0);
    }
}
void PrintTree(TREE T){
    if(T!=NULL){
        PrintTree(T->pRight);
        cout<<T->key<<" "; 
        PrintTree(T->pLeft);
    }
}



//

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTree(T);
	return 0;
}
