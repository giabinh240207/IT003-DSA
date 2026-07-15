
#include <iostream>

using namespace std;

bool binary_search(int a[] , int left , int right, int x){
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]==x) return true;
        else if(a[mid]<x) left=mid+1;
        else if(a[mid]>x) right =mid -1; 
    }
    return false;
}

int main() {
    int x; cin >> x;
    int n; cin >> n;

    int *a=new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << std::boolalpha << binary_search(a, 0, n-1, x);;

    return 0;
}


