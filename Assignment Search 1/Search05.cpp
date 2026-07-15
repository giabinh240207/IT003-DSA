
#include <iostream>

using namespace std;

bool binary_search(int a[], int left , int right , int x){
    int mid=(left+right)/2;
    if(left>right) return false;
    if(a[mid]==x) return true;
    else if(a[mid]>x) return binary_search(a, mid+1,right,x);
    else if(a[mid]<x) return binary_search(a,left,mid-1,x);
    return false;
}


int main() {
    int x; cin >> x;
    int n; cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << std::boolalpha << binary_search(a, 0, n-1, x);

    return 0;
}

