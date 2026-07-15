
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
    root->pRight=root->pLeft=NULL;
    return root;
}
void Insert(TREE & root,int x){
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
int CountNode_Have1Child(TREE root){
    if(root==NULL) return 0;
    int leftnode=CountNode_Have1Child(root->pLeft);
    int rightnode=CountNode_Have1Child(root->pRight);
    if((root->pLeft==NULL&&root->pRight!=NULL)||(root->pLeft!=NULL&&root->pRight==NULL)) 
        return 1+leftnode + rightnode;
    return leftnode+rightnode;
}



//

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << CountNode_Have1Child(T);
	return 0;
}
