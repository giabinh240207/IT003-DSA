
#include<iostream>

void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
    std::cout << std::endl;
}
//code here
#define MAXN 1000
using namespace std;
void NhapMang(int a[], int &n){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}
void SapXepSoDuongGiamAmTangVa0(int a[], int n){
    // sap xep so duong tang dan
    for(int i=1;i<n;i++){
        int x = a[i];
        int j=i-1;
        while(j>=0 && a[j]< x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
    // sap xep so am tang dan
    for(int i=0;i<n-1;i++){
        int min =i;
        if(a[min]>0) continue;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]) min =j;
        }
        swap(a[i],a[min]);
    }
}
//
int main() {
    int a[MAXN], n;
    NhapMang(a, n);
    SapXepSoDuongGiamAmTangVa0(a, n);
    XuatMang(a, n);
    return 0;
}
