
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_leastGreater_firstOccurrence(int a[],int n, int x){
    int res=-1;
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid =(left+right)/2;
        if(a[mid]<=x) left = mid+1;
        else{
            res=mid;
            right=mid-1;
        }
    }
    return res;
}


int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_leastGreater_firstOccurrence(a, n, x);

    return 0;
}


