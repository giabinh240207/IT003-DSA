
#include <iostream>
using namespace std;
#define M 100

struct NODE {
    int key;
    NODE *pNext;
};
// Khai báo kiểu con trỏ chỉ node
typedef NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	p->key = x;
	p->pNext = NULL;
	return p;
}
void AddTail(NODE* &head, int x) {
	NODE *p=CreateNode(x);
    if (head == NULL) head = p;
	else {
        NODE* i=head;
        while(i->pNext!=NULL){
            i=i->pNext;
        }
        i->pNext=p;
    }
}

int HF(int numbucket, int key) { return key % numbucket; }

void InitHashTable(HASHTABLE &H, int numbucket) {
    for (int i = 0; i<numbucket; i++)
        H[i] = NULL;
}

void TraverseBucket(HASHTABLE H, int i) {
    NODEPTR p = H[i];
    while (p != NULL) {
        cout << " --> " << p->key;
        p = p->pNext;
    }
}
void Traverse(HASHTABLE H, int numbucket) {
    for (int i = 0; i<numbucket; i++) {
        cout << i ;
        TraverseBucket(H, i);
        cout << endl;
    }
}
//code here

void Insert(HASHTABLE &H, int numbucket, int x) {
    int index = HF(numbucket, x);
    AddTail(H[index], x);
}

void CreateHashTable(HASHTABLE &H, int &numbucket) {
    cin >> numbucket;

    InitHashTable(H, numbucket);

    int x;
    while (cin >> x) {
        if (x == -1)
            break;

        Insert(H, numbucket, x);
    }
}

int Remove(HASHTABLE &H, int numbucket, int x) {
    int index = HF(numbucket, x);

    NODEPTR p = H[index];
    NODEPTR prev = NULL;

    while (p != NULL) {
        if (p->key == x) {
            if (prev == NULL) {
                H[index] = p->pNext;
            } else {
                prev->pNext = p->pNext;
            }

            delete p;
            return 1;
        }

        prev = p;
        p = p->pNext;
    }

    return 0;
}


//


int main(){
    HASHTABLE H;
    int numbucket;
    int x;

    CreateHashTable(H, numbucket);

    Traverse(H, numbucket);

    cin >> x;
    if (Remove(H, numbucket, x)) {
        cout << endl << x << ": Delete Successful."  << endl << endl;
        Traverse(H, numbucket);
    }
    else cout << endl << x << ": Delete Failed." << endl << endl;

    return 0;
}
