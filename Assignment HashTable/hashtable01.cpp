
#include <iostream>
#include <string>

#define LOAD 0.7
using namespace std;

struct Hocsinh { // cau truc cua struct 
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};
// cau truc cua linked list
struct Node {  // node
    Hocsinh data;
    Node *next;
};

struct List { // list
    Node * head, *tail;
};
// cac ham thao tac cua linked list
Node * CreateNode(Hocsinh); // ham tao node
void CreateList(List &); // ham tao list
void AddTail(List&, Hocsinh); // ham them vao sau list
int RemoveHead(List &); // ham xao dau 
int RemoveAfter(List &, Node *); // ham xoa cuoi
void DeleteList(List &); // ham xoa toan bo list

// cau truc bang bam
struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};

void CreateHashtable(Hashtable &, int); // ham tao bang bam 
int Hash(Hashtable, int); // Ham bam ma so hoc sinh thanh chi so
int Insert(Hashtable &, Hocsinh); // ham them phan tu hay ham input 
void PrintHashtable(Hashtable); // ham output bang bam 
void DeleteHashtable(Hashtable &); // ham xoa bang bam 


// ham nhap cac thanh phan cua hoc sinh 
void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
void CreateList(List &l) { // ham tao list rong 
    l.head = l.tail = NULL;
}

Node * CreateNode(Hocsinh x) { // ham tao node
    Node *p = new Node;
    if (p == NULL)
        exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}

void AddTail(List &l, Hocsinh x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = l.tail = p;
    else {
        l.tail->next = p;
        l.tail = p;
    }
}

int RemoveHead(List &l) {
    if (l.head == NULL)
        return 0;
    Node *p = l.head;
    l.head = p->next;
    if (l.tail == p)
        l.tail = NULL;
	delete p;
    return 1;
}

int RemoveAfter(List &l, Node *q) {
    if (l.head == NULL)
        return 0;

    if (q == NULL)
        return RemoveHead(l);

    Node *p = q->next;
    q->next = p->next;
    if (l.tail == p)
        l.tail = q;
    delete p;
    return 1;
}

void DeleteList(List &l) {
    while (l.head) {
        Node *p = l.head;
        l.head = p->next;
        delete p;
    }
    l.head = l.tail = NULL;
}

void CreateHashtable(Hashtable &ht, int m) { // ban chat cua hash table la mot mang cac linked list 
    ht.table = new List[m]; // khoi tao mang linked list 
    for (int i = 0; i < m; i++) 
        CreateList(ht.table[i]); // tao linked list rong cho tung mang trong hash table 
    ht.M = m; // khoi tao kich thuoc cua mang 
    ht.n = 0; // hien tai chua co phan tu nao trong hash table 
}

int Hash(Hashtable ht, int maso) { //hash function 
    return maso % ht.M;
}

void PrintHashtable(Hashtable ht) { // nhin giong voi print trong linked list 
    for (int i = 0; i < ht.M; i ++) {
        Node *p = ht.table[i].head;
        while (p) {
            Hocsinh hs = p->data;
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "] ";
            p = p->next;
        }
        cout << '\n';
    }
}

void DeleteHashtable(Hashtable &ht) {
    for (int i = 0; i < ht.M; i++) {
        DeleteList(ht.table[i]);
    }
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int Insert(Hashtable &ht, Hocsinh x) {
//code here
    if ((double)(ht.n + 1) / ht.M > LOAD)
        return 0;

    // Tính vị trí băm từ mã số học sinh
    int index = Hash(ht, x.Maso);

    // Kiểm tra mã số đã tồn tại trong danh sách tại vị trí index chưa
    Node *p = ht.table[index].head;
    while (p != NULL) {
        if (p->data.Maso == x.Maso)
            return 0; // bị trùng mã số, không thêm
        p = p->next;
    }

    // Nếu không trùng thì thêm vào cuối danh sách liên kết
    AddTail(ht.table[index], x);

    // Tăng số phần tử trong bảng băm
    ht.n++;

    return 1;
//

}