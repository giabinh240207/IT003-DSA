
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode* TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}

//code here
void Input(vector<int>&A){
    int x;
    while(true){
        cin>> x;
        if(x==-1) break;
        A.push_back(x);
    }
    if(A.empty()){
        cout<<"Empty Tree";
        exit(0);
    }
}
int Sum_NODE(TREE root,int k){
    if(root==NULL) return 0;
    int leftnode=Sum_NODE(root->left,k-1);
    int rightnode=Sum_NODE(root->right,k-1);
    if(k==0){
        return root->key;
    }
    return leftnode+rightnode;
}
void Fun(TREE root){
    int k;
    cin >> k;
    if(Sum_NODE(root,k)==0){
        cout <<"No Find";
        return;
    }
    else cout << Sum_NODE(root,k);
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
