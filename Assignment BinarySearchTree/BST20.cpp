
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
        TREE p = new TNODE;
        if(p==NULL) exit(1);
        p->key=x;
        p->pLeft=p->pRight=NULL;
        return p;
    }
    void Insert(TREE & root, int x){
        if(root==NULL){
            root=CreateNODE(x);
        }
        else{
            if(x<root->key) Insert(root->pLeft,x);
            else if(x>root->key) Insert(root->pRight,x);
        }
    }

    void CreateTree(TREE & root){
        int x;
        while(true){
            cin >> x;
            if(x==-1) break;
            Insert(root, x);
        }
    }
    int CountNodeChild(TREE root){
        if(root==NULL) return 0;
        return 1+CountNodeChild(root->pLeft)+CountNodeChild(root->pRight);
    }
    void TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE  root){
        if(root!=NULL){
            TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(root->pLeft);
            int left=CountNodeChild(root->pLeft);
            int right=CountNodeChild(root->pRight);
            if(left-right==1) cout<<root->key<<" ";
            TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(root->pRight);
        }
    }
    //
    int main() {
        TREE T; //hay: TNODE* T;
        T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)

        CreateTree(T);

        if(T==NULL) cout << "Empty Tree.";
        else TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T);
        return 0;
    }
