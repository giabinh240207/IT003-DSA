
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//code here

void CreateEmptyTree(TREE& T){ //tao cay rong
    T=NULL;
} 
TREE CreateNODE(int x){ // ham tao node cau cay
    TREE p;
    p=new TNODE;
    if(p==NULL){
        exit(1);
    }
    p->key=x;
    p->pLeft=p->pRight=NULL;
    return p;
}
void InsertNode(TREE& root,int x){ // ham them node
    if(root==NULL){ // neu cay rong thi tao node dau tien cho cay
        root=CreateNODE(x);
        return;
    }
    // Neu cay khong rong
    if(x<root->key){  // neu x nho hon gia tri cua node goc
        InsertNode(root->pLeft,x) ;// goi de quy tao node ben trai cua cay bang x
    }
    else if(x>root->key){ // neu x lon hon gia tri cua node goc
        InsertNode(root->pRight,x);// goi de quy tao node ben phai cua cay bang x 
    }
}
void CreateTree(TREE& root){ //ham tao cay hoan chinh
    CreateEmptyTree(root);
    int x;
    while(true){
        cin >> x;
        if(x==-1) break;
        InsertNode(root,x); // goi ham them cho den khi rung lai
    }
    if(root==NULL){
        cout<<"Empty Tree.";
        exit(0);
    }
}
void PrintTree(TREE root){
    if(root!=NULL){
        PrintTree(root->pLeft);
        cout << root->key<<" ";
        PrintTree(root->pRight);
    }
}

//

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTree(T);
	return 0;
}
