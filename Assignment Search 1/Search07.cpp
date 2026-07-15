
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_greatestLesser_last_occurrence(int a[], int n , int x){
    int left=0;
    int right = n-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(a[mid]>=x) right = mid-1;
        for(int i=right;i>=mid;i--){
            if(a[i]<x) return i;
        }
    }
    return -1;
}


int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_greatestLesser_last_occurrence(a, n, x);

    return 0;
}


