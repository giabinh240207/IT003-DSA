
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
void CreateTree(TREE & root){
    int x;
    while(true){
        cin>>x;
        if(x==-1) break;
        TREE p=CreateTNode(x);
        Insert(root,p);
    }
    if(root==NULL){
        cout<<"Empty Tree.";
        exit(0);
    }
}
int getLevel(TREE root, int target, int level){ // ham tinh level cua node x 
    if(root==NULL) return -1;
    if(target==root->key) return level;
    else if(target<root->key) return getLevel(root->pLeft,target,level+1);
    return getLevel(root->pRight, target, level+1);
}
bool searchTREE(TREE root,int x){ // ham tim xem x co trong cay hay khong 
    if(root==NULL) return false;
    if(x==root->key) return true;
    else if(x<root->key) return searchTREE(root->pLeft,x);
    else return searchTREE(root->pRight,x);
    return false;
}
TREE Find_Parrent(TREE root, int x){ // ham tim node cha 
    if(root==NULL) return NULL;
    if(root->pLeft!=NULL&&root->pLeft->key==x||root->pRight!=NULL&&root->pRight->key==x) return root;
    else if(x<root->key) return Find_Parrent(root->pLeft,x); 
    return Find_Parrent(root->pRight,x);
}
void FindSiblings(TREE root, int x){  // ham tong quat 
    if(!searchTREE(root,x)){  
        cout<< "Not found "<<x<<'.';
        return;
    }
    if(getLevel(root,x,0)==0){
        cout << x <<" is Root.";
        return;
    }
    else{
        TREE Father=Find_Parrent(root,x);
        if(Father->pLeft==NULL||Father->pRight==NULL){ // neu node cha chi co con trai hoac con phai thi khong co ho hang
            cout<<x<<" has no siblings.";
            return;
        }
        else{ // neu node cha co ca hai thi co ho hang
            cout<<Father->pLeft->key<<" and "<<Father->pRight->key<<" are siblings.";
            return;
        }
        
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
