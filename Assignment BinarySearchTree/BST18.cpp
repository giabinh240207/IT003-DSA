
#include <iostream>
#include <queue>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//code here
TREE createNODE(int x){
    TREE p= new TNODE;
    p->key=x;
    p->pLeft=p->pRight=NULL;
    return p;
}

void Insert(TREE& root, int x){
    if(root==NULL){
        root=createNODE(x);
        return;
    }
    if(x>root->key) Insert(root->pRight,x);
    else if(x<root->key) Insert(root->pLeft,x);
}
void CreateTree(TREE& root){
    int x;
    while(true){
        cin>>x;
        if(x==-1) break;
        Insert(root,x);
    }
    if(root==NULL){
        cout<<"Empty Tree.";
        exit(0);
    }
}
bool searchNODE(TREE root, int x){ // ham tim x co trong node hay khong 
    if(root==NULL) return false;
    if(x==root->key) return true;
    else if(x<root->key) return searchNODE(root->pLeft,x);
    else return searchNODE(root->pRight,x);
    return false;
} 
int getLevel(TREE root, int x,int level){
    if(root==NULL) return -1;
    if(x==root->key) return level;
    else if(x<root->key) return getLevel(root->pLeft,x,level+1);
    return getLevel(root->pRight,x,level+1);
}
bool PrintAncestorsHelper(TREE root, int x){
    if(root == NULL) return false;

    if(root->key == x) return true;

    if(PrintAncestorsHelper(root->pLeft, x) ||
       PrintAncestorsHelper(root->pRight, x)){
        cout << root->key << " ";
        return true;
    }

    return false;
}

void PrintAncestors(TREE root, int x){
    if(!searchNODE(root,x)){
        cout<<-1;
        return;
    }
    if(getLevel(root,x,0)==0){
        cout<<"Node is root.";
        return;
    }
    else{
        PrintAncestorsHelper(root,x);
    }
}

//

int main() {
	TNODE* T;
	int x;

	cin >> x;

	T = NULL;
	CreateTree(T);

	PrintAncestors(T, x);

	return 0;
}
