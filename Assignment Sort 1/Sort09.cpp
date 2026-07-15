//code here
#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
#define MAXN 100

int Input(){
    int n;
    cin >> n;
    return n;
}

void NhapMang(int a[],const int &n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}
void SapXepSoChanGiamDan(int a[], int n){
    for(int i=0;i<n-1;i++){
        int max = i;
        if(a[max]%2!=0) continue;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[max]&&a[j]%2==0) max =j;
        }
        swap(a[i],a[max]);
    }
}

//
void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
}
int main() {
    int a[MAXN], n;
    n=Input();
    NhapMang(a, n);
    SapXepSoChanGiamDan(a, n);
    XuatMang(a, n);
    return 0;
}
