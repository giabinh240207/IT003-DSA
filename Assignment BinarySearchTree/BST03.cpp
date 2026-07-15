
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//code here
TREE CreateNODE(int x){
    TREE root;
    root=new TNODE;
    if(root==NULL) exit(1);
    root->key=x;
    root->pRight=root->pLeft=NULL;
    return root;
}
void Insert(TREE& root, int x){
    if(root==NULL){
        root=CreateNODE(x);
        return;
    }
    if(root->key>x) Insert(root->pLeft,x);
    else if(root->key<x) Insert(root->pRight,x);
}
void CreateTree(TREE & root){
    int x;
    while(true){
        cin >> x;
        if(x==-1) break;
        Insert(root,x);
    }
}
bool searchNode(TREE root, int x){
    if(root==NULL) return false;
    if(x==root->key) return true;
    else if(x<root->key) return searchNode(root->pLeft,x);
    else return searchNode(root->pRight,x);
    return false;
}


//

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;
	if(searchNode(T, x)) cout << "true";
	else cout << "false";
	return 0;
}
