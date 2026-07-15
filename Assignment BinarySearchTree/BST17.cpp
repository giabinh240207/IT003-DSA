
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;


void CreateEmptyTree(TREE &T) {
	T = NULL;
}
TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}
//code here
void CreateTree(TREE& root){
    int x;
    while(true){
        cin >> x;
        if(x==-1) break;
        TREE p = CreateTNode(x);
        Insert(root,p);
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
TREE Node_parent(TREE root, int x){
    if(root==NULL) return NULL;
    if(root->pLeft!=NULL&&root->pLeft->key==x||root->pRight!=NULL&&root->pRight->key==x)
        return root;
    if(x<root->key) return Node_parent(root->pLeft,x);
    return Node_parent(root->pRight,x);
}
void FindSiblings(TREE root, int x){
    if(!searchNODE(root,x)){
        cout<<"Not found "<<x<<'.';
        return;
    }
    if(getLevel(root,x,0)==0){
        cout<<x<<" has no parent.";
        return;
    }
    else{
        cout<<Node_parent(root,x)->key<<" is parent of "<< x<<'.';
    }
    
}

//

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	FindSiblings(T, x);

	return 0;
}
