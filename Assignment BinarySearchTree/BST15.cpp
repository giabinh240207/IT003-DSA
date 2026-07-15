
#include <iostream>
#include <queue>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

// code here
TREE createNODE(int x){
    TREE root;
    root=new TNODE;
    if(root==NULL) exit(1);
    root->key=x;
    root->pRight=root->pLeft=NULL;
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
        cin >>x;
        if(x==-1) break;
        Insert(root,x);
    }
}
int getLevel(TREE root, int x, int currlevel){
    if(root==NULL) return -1;
    if(x==root->key) return currlevel;
    else if(x<root->key) return getLevel(root->pLeft,x,currlevel+1);
    return getLevel(root->pRight,x,currlevel+1);
}
void PrintLevel(TREE root, int target, int& level){
    level=getLevel(root,target,0);
}



//



int main() {
	TNODE* T;
	int x, level=-1;

	cin >> x;

	T = NULL;
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else {
		PrintLevel(T, x, level);
		cout << level;
	}
	return 0;
}

