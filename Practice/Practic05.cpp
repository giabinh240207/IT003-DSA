#include <iostream>

using namespace std;

void QuickSort(int [] , int, int);

int main()
{
    int *ls = NULL;
    int n;
    cin >> n;
    ls = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> ls[i];
    }
    QuickSort(ls, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << ls[i] << ' ';
    }
    delete [] ls;
    return 0;
}

void QuickSort(int ls[], int b, int e) { 
    if(e<=b) return;
    int i=b;
    int j=e;
    int pivot=ls[(b+e)/2];
    while(i<=j){
        while(ls[i]<pivot) i++;
        while(ls[j]>pivot) j--;
        if(i<=j){
            swap(ls[i],ls[j]);
            i++;
            j--;
        }
    }
    QuickSort(ls,b,j);
    QuickSort(ls,i,e);
}
