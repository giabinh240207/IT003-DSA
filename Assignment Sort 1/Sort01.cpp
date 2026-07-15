#include <iostream>
#include <string>
#define MAXN 100000

void NhapMang(int a[],int n){
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
}
void selection_sort_ascending(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]) min=j;
        }
        std::swap(a[min],a[i]);
    }
}
bool is_ascending(int a[],int n){
    bool isIncreasing = true;
    bool isDecreasing = true;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]) isIncreasing=false;
        else if (a[i]<a[i+1]) isDecreasing=false;
    }
    return isIncreasing;
}

int main() {
    int a[MAXN], n;

    std::cin >> n;

    NhapMang(a, n);

    selection_sort_ascending(a, n);

    std::cout << std::boolalpha << is_ascending(a, n);

    return 0;
}
