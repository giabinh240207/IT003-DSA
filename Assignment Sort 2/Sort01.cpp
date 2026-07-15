
#include <iostream>
#define MAXN 200000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
//code here
using namespace std;
void Heapify(int a[], int& heapSize , int k){
    int j=2*k+1;
    while(j<heapSize){
        if(j+1<heapSize){
            if(a[j]<a[j+1]) j++;
        }
        if(a[j]<=a[k]) return;
        swap(a[j],a[k]);
        k=j;
        j=2*k+1;
    }
}

void buildHeap(int a[], int heapSize){
    if(heapSize==0){
        cout<<heapSize;
        exit(0);
    }
    int i=(heapSize-1)/2;
    while(i>=0){
        Heapify(a,heapSize,i);
        i--;
    }
}

//

void HeapSort(int a[], int n) { //khau sap xep
	int heapSize;
	heapSize = n;
	buildHeap(a, heapSize);
	for (int i = n - 1; i>0; i--) {
		swap(a[0], a[i]);
		heapSize -= 1;
		Heapify(a, heapSize, 0);
	}
}

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    HeapSort(a, n);

    XuatMang(a, n);

    return 0;
}
