
#include <iostream>
#define MAXN 30000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
// code here
void insertionSort_sort_decending(int a[], const int&n){
    for(int i=1;i<n;i++){
        int x= a[i];
        int j=i-1;
        while(j>=0 && a[j]<x){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=x;
    }
}
//c
void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    insertionSort_sort_decending(a, n);

    XuatMang(a, n);

    return 0;
}
