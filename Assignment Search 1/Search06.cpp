
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_first_occurrence(int a[],int n,int x){
    int left=0;
    int right =n-1;
    int t=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]==x) t=mid;
        if(a[mid]<x) left=mid+1;
        if(a[mid]>=x) right =mid -1; 
    }
    return t;
}


int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_first_occurrence(a, n, x);

    return 0;
}


