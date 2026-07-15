
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;
// code here
#include <queue>
TREE createNODE(int x){
    TREE p= new TNODE;
    p->key=x;
    p->pLeft=p->pRight=NULL;
    return p;
}

void Insert(TREE & root, int x){
    if(root==NULL){
        root=createNODE(x);
        return;
    }
    else{
        if(x<root->key) Insert(root->pLeft,x);
        else Insert(root->pRight,x);   
    }
}

void CreateTree(TREE & root){
    int x;
    while(true){
        cin >> x;
        if(x==-1) break;
        Insert(root,x);
    }
}
void Replace(TREE &p, TREE & q){
    if(q->pLeft!=NULL) Replace(p,q->pLeft);
    else{
        p->key=q->key;
        p=q;
        q=q->pRight;
    }
}
void DeleteNode(TREE & root, int x ){
    if(root == NULL ) return;
    else{
        if(root->key<x) return DeleteNode(root->pRight,x);
        else{
            if(root->key>x) return DeleteNode(root->pLeft,x);
            else{
                TREE p=root;
                if(root->pLeft==NULL) root=root->pRight;
                else{
                    if(root->pRight==NULL) root=root->pLeft;
                    else Replace(p,root->pRight);
                }
                delete p;
            }
        }
    }
}
void PrintTree(TREE root){
    if(root==NULL){
        cout<<"Empty Tree.";
        return;
    };
    queue<TREE>q;
    q.push(root);
    while(!q.empty()){
        TREE p=q.front();
        q.pop();
        cout<<p->key<<" ";
        if(p->pLeft!=NULL) q.push(p->pLeft);
        if(p->pRight!=NULL) q.push(p->pRight);
    }

}
//
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	DeleteNode(T, x);

	PrintTree(T);
	return 0;
}
