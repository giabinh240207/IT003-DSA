
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode {
    int key;
    TNode *left, *right;
}; // khoi tao node

typedef TNode* TREE; // khoi tao cay 

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) { //ham tao cay tu NLR va LNR
	int i;  
	TREE root;
	if (inE < inB) return NULL; 
	root = new TNode; 
	if (root != NULL) { 
		root->key = pre[preB]; 
		for (i = inB; i <= inE; i++) 
			if (in[i] == pre[preB]) break; // tìm node gốc trong LNR
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}
//code here
bool is_prime(int x){  //ham kiem tra so nguyen to
    if(x<2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

void Input(vector<int>& data){ //nhap cac node cua cay vao vector
    int x; 
    while(true){
        cin >> x;
        if(x==-1) break;
        data.push_back(x);
    }
    if(data.empty()){
         cout << "Empty Tree";
         exit(0);
    }
}
int Tree_Prime(TREE root){
    if(root==NULL) return 0;
    int count=0;
    if(is_prime(root->key)) count =1;
    return count+Tree_Prime(root->left)+Tree_Prime(root->right);
}
void Fun(TREE& root){
    if(root==NULL){
        cout << "Empty Tree";
        return;
    }
    cout << Tree_Prime(root);
}
//


int main() {
    vector<int> duyetNLR;
    vector<int> duyetLNR;
    Input(duyetNLR);
    Input(duyetLNR);
    int Num=duyetNLR.size()-1; 
    TREE root = CreateTree(duyetNLR, duyetLNR, 0, Num, 0, Num);
    Fun(root);
    return 0;
}
