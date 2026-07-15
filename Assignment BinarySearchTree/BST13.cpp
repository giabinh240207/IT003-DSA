
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
void Insert(TREE& root, int x){
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

TREE FindMax(TREE root){
    if(root==NULL) return NULL;
    while(root->pRight){
        root=root->pRight;
    }
    return root;
}



//

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << FindMax(T)->key;
	return 0;
}
