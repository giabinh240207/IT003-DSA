
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
    TREE root=new TNODE;
    if(root==NULL) exit(1);
    root->key=x;
    root->pLeft=root->pRight=NULL;
    return root;
}
void Insert(TREE &T, int x){
    if(T==NULL){
        T=createNODE(x);
        return;
    }
    if(x<T->key) Insert(T->pLeft,x);
    else if(x>T->key) Insert(T->pRight,x);
}
void CreateTree(TREE& root){
    int x;
    while(true){
        cin>>x;
        if(x==-1) break;
        Insert(root,x);
    }
}
int Height(TREE root){
    if(root==NULL) return -1;
    return 1 + max(Height(root->pLeft), Height(root->pRight));
}

int HeightOfNode(TREE root,int x){
    if(root==NULL) return -1;
    if(root->key==x) return Height(root);

    if(x < root->key)
        return HeightOfNode(root->pLeft, x);
    else
        return HeightOfNode(root->pRight, x);
}



//


int main() {
	TREE T;
	int x;

	cin >> x;

	T = NULL;
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << HeightOfNode(T, x);

	return 0;
}
