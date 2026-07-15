

#include <iostream>
using namespace std;

#define MAXTABLESIZE 10000

struct NODE {
    int key;
};
typedef NODE HASHTABLE[MAXTABLESIZE];

int TableSize;
int M;

int HF(int key) {
    return key%M;
}
int HF_LinearProbing(int key, int i) {
    return (HF(key) + i) % TableSize;
}
///code here

void Init(HASHTABLE&ht){
    for(int i=0;i<TableSize;i++){
        ht[i].key=-1;
    }
}
int Insert(HASHTABLE&ht , int &size, int key){
    if(size>=TableSize) return 0;
    for(int i=0;i<TableSize;i++){
        int pos=HF_LinearProbing(key,i);
        if(ht[pos].key==-1){
            ht[pos].key=key;
            size++;
            return 1; 
        }
    }
    return 0;
}
void CreateHashTable(HASHTABLE& ht, int& size){
    cin >> M;
    cin>>TableSize;
    size=0;
    Init(ht);
    int x;
    while(true){
        cin >> x;
        if(x==-1) break;
        Insert(ht,size,x);
    }
}
void Traverse(HASHTABLE ht, int size){
    for(int i=0;i<TableSize;i++){
        cout << i << " --> " << ht[i].key<<endl;;
    }
}


//

int main(){
    HASHTABLE H;
    int CurrentSize; // so phan tu trong hash table 

    CreateHashTable(H, CurrentSize);
    Traverse(H, CurrentSize);

    return 0;
}
