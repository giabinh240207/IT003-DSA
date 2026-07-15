
#include <iostream>
#define MAXN 400000

void NhapMang(int a[], int &n){
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
}
int LinearSearch(int a[], int n , int x){
    bool flas=false;
    for(int i=0;i<n;i++){
        if(a[i]==x) flas=true;
        else continue;
    }
    if(flas) return x;
    else return -1;
}

int main() {
    int a[MAXN], n, x;

    std::cin >> x;

    NhapMang(a, n);

    int i= LinearSearch(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";
    return 0;
}
