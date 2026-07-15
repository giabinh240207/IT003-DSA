//code here
#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
#define MAXN 100

void NhapMang(int a[],int &n){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void SapXepSoAmTangDan(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        if(a[min]>=0) continue;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]) min=j;
        }
        swap(a[i],a[min]);
    }
}

//
void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
}
int main() {
    int a[MAXN], n;
    NhapMang(a, n);
    SapXepSoAmTangDan(a, n);
    XuatMang(a, n);
    return 0;
}
