
    #include <iostream>
    using namespace std;

    struct TNODE {
        int key;
        TNODE* pLeft;
        TNODE* pRight;
    };
    typedef TNODE* TREE;
    // code here
    TREE createNODE(int x) {
        TREE p = new TNODE;
        p->key = x;
        p->pLeft = p->pRight = NULL;
        return p;
    }

    void Insert(TREE &root, int x) {
        if (root == NULL) {
            root = createNODE(x);
        } else {
            if (x < root->key) {
                Insert(root->pLeft, x);
            } else if (x > root->key) {
                Insert(root->pRight, x);
            }
        }
    }

    void CreateTree(TREE &root) {
        int x;
        while (true) {
            cin >> x;
            if (x == -1) break;
            Insert(root, x);
        }
    }

    void Replace(TREE &p, TREE &q) {
        if (q->pLeft != NULL) {
            Replace(p, q->pLeft);
        } else {
            p->key = q->key;
            p = q;
            q = q->pRight;
        }
    }

    void DeleteNode(TREE &root, int x) {
        if (root == NULL) return;
        
        if (x < root->key) {
            DeleteNode(root->pLeft, x);
        } 
        else if (x > root->key) {
            DeleteNode(root->pRight, x);
        } 
        else {
            // Tìm thấy node cần xóa
            TREE p = root;
            if (root->pLeft == NULL) {
                root = root->pRight;
            } 
            else if (root->pRight == NULL) {
                root = root->pLeft;
            } 
            else {
                Replace(p, root->pRight);
            }
            delete p;
        }
    }

    
    void NLR(TREE root) {
        if (root != NULL) {
            cout << root->key << " ";
            NLR(root->pLeft);
            NLR(root->pRight);
        }
    }

    void PrintTree(TREE root) {
        if (root == NULL) {
            cout << "Empty Tree.";
        } else {
            NLR(root);
        }
    }
   
    //
    int main() {
        TREE T; 
        T = NULL; 
        CreateTree(T);

        int x;
        cin >> x;

        DeleteNode(T, x);

        PrintTree(T);
        return 0;
    }
