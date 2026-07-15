
#include <iostream>
#include <climits>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

//code here
using namespace std;
void merge(int a[],int left,int mid , int right){
    if(right==0){
        cout<<0;
        exit(0);
    }
    int m=left;
    int n=mid+1;
    int k=0;
    int *temp=new int[right-left+1];
    while (m <= mid && n <= right) {
        if (a[m] <= a[n]) {
            temp[k++] = a[m++];
        } else {
            temp[k++] = a[n++];
        }
    }
    while (m <= mid) {   
        temp[k++] = a[m++];
    }
    while (n <= right) {
        temp[k++] = a[n++];
    }
    for(int i=0;i<k;i++){
        a[left+i]=temp[i];
    }
    delete []temp;
}

//

void mergeSortRange(int input[], int from, int to) { 
    if (from < to) {
        int middle = (from + to) / 2;
        mergeSortRange(input, from, middle);
        mergeSortRange(input, middle + 1, to);
        merge(input, from, middle, to);
    }
}

void mergeSort(int input[], int n) {
    mergeSortRange(input, 0, n - 1);
}

void XuatMang(int A[], const int &N) {
    // std::cout << is_ascending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}


int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    mergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
