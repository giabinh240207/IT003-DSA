#include <iostream>
using namespace std;

struct DONTHUC{
    float HeSo;
    int SoMu;
};
struct NODE {
	DONTHUC info;
	NODE* pNext;
};
struct DATHUC {
	NODE* pHead;
	NODE* pTail;
};

void CreateEmptyDATHUC(DATHUC& L) {
    L.pHead = L.pTail = NULL;
}

NODE* CreateNode(float heso, int somu) {
    NODE* newNode = new NODE;
    newNode->info.HeSo = heso;
    newNode->info.SoMu = somu;
    newNode->pNext = NULL;
    return newNode;
}

void Sort(DATHUC &L) {
    if (L.pHead == NULL || L.pHead->pNext == NULL) return;

    for (NODE* i = L.pHead; i->pNext != NULL; i = i->pNext) {
        NODE* minNode = i; 
        for (NODE* j = i->pNext; j != NULL; j = j->pNext) {
            if (j->info.SoMu < minNode->info.SoMu) {
                minNode = j;
            }
        }
        if (minNode != i) {
            DONTHUC temp = i->info;
            i->info = minNode->info;
            minNode->info = temp;
        }
    }
}

void Normalize(DATHUC &L) {
    if (L.pHead == NULL) return;
    NODE* p = L.pHead;
    while (p != NULL && p->pNext != NULL) {
        if (p->info.SoMu == p->pNext->info.SoMu) {
            p->info.HeSo += p->pNext->info.HeSo;
            NODE* temp = p->pNext;
            p->pNext = temp->pNext;
            if (temp == L.pTail) {
                L.pTail = p;
            }   
            delete temp;
        } else {
            p = p->pNext;
        }
    }
    // xoa so 0 
    NODE* curr = L.pHead;
    NODE* prev = NULL;
    while (curr != NULL) {
        if (curr->info.HeSo == 0) {
            NODE* temp = curr;
            if (prev == NULL) { // Xóa đầu
                L.pHead = curr->pNext;
                curr = L.pHead;
            } else {
                prev->pNext = curr->pNext;
                curr = prev->pNext;
            }
            if (temp == L.pTail) L.pTail = prev;
            delete temp;
        } else {
            prev = curr;
            curr = curr->pNext;
        }
    }
}

void AddTail(DATHUC& L, float heso, int somu) {
    NODE* newNode = CreateNode(heso, somu);
    if (L.pHead == NULL) {
        L.pHead = L.pTail = newNode;
    } else {
        L.pTail->pNext = newNode;
        L.pTail = newNode;
    }
}

void CreatePolynomial(DATHUC& L) {
    int n;
    float h;
    int s;
   
    if (!(cin >> n)) return;
    for (int i = 0; i < n; i++) {
        cin >> h >> s;
        if (h != 0) { 
            AddTail(L, h, s);
        }
    }
    Sort(L);
    Normalize(L);
}

void Output(DONTHUC a){
    if(a.HeSo==-1) cout << "-";
	else if(a.HeSo==1) cout << "";
	else cout << a.HeSo;

    if(a.SoMu==0) cout << "";
	else if(a.SoMu==1) cout << "x";
	else if(a.SoMu<1) cout << "-x";
    else // s.SoMu>1
		cout << "x^" << a.SoMu;
}

void Output(DATHUC L) {
	NODE* p;
	if (L.pHead == NULL)
		cout << "Empty DATHUC.";
	else {
		p = L.pHead;
		Output(p->info);
		p=p->pNext;
		while (p) {
			cout << " + "; Output(p->info);
			p = p->pNext;
		}
	}
}

int main() {
    DATHUC poly;
	CreateEmptyDATHUC(poly);
    CreatePolynomial(poly);
	Output(poly);
	return 0;
}
