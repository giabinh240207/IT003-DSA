
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//code here
TREE createNODE(int x){
    TREE root;
    root=new TNODE;
    if(root==NULL) exit(1);
    root->key=x;
    root->pLeft=root->pRight=NULL;
    return root;
}
void Insert(TREE& T, int x){
    if(T==NULL){
        T=createNODE(x);
        return;
    }
    if(x>T->key) Insert(T->pRight,x);
    else if(x<T->key) Insert(T->pLeft,x);
}
void CreateTree(TREE & root){
    int x;
    while(true){
        cin>> x;
        if(x==-1) break;
        Insert(root,x);
    }
}

int CountNode(TREE root){
    if(root==NULL) return 0;
    int leftnode=CountNode(root->pLeft);
    int rightnode=CountNode(root->pRight);
    return 1+leftnode+rightnode;
}


//

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << CountNode(T);
	return 0;
}
