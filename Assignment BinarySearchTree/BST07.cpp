
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
    if(root==NULL) exit(1);;
    root->key=x;
    root->pLeft=root->pRight=NULL;
    return root;
}
void Insert(TREE & root, int x){
    if(root==NULL){
        root=createNODE(x);
        return;
    }
    if(x<root->key) Insert(root->pLeft,x);
    else if(x>root->key) Insert(root->pRight,x);
}
void CreateTree(TREE& root){
    int x;
    while(true){
        cin >> x;
        if(x==-1) break;
        Insert(root,x);
    }
}
int CountNODE(TREE root){
    if(root==NULL) return 0;
    int leftnode=CountNODE(root->pLeft);
    int rightnode=CountNODE(root->pRight);
    if(root->pLeft==NULL&&root->pRight==NULL)
        return 1 + leftnode+rightnode;
    return leftnode+rightnode;
}
void CountLeaf(TREE root , int& x){
    x=CountNODE(root);
}

// 

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int count =0;
	CountLeaf(T, count);
	cout << count;
	return 0;
}
