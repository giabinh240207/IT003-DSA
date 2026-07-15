
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}

//code here
void quickSort(vector<int>& A, int left,int right){
    if(left>=right) return;
    int x=A[(left+right)/2];
    int i=left;
    int j=right;
    while(i<j){
        while(A[i]>x) i++;
        while(A[j]<x) j--;
        if(i<=j){
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }
    quickSort(A,left,j);
    quickSort(A,i,right);
}
void QuickSort(vector<int> A, int left , int right){
    if(A.size()==0){
        cout<<0;
        return;
    }
    quickSort(A,left,right);
    for(int x:A){
        cout<<x<<" ";
    }
}

//

int main() {
	vector<int> A;
	Input(A);
	QuickSort(A,0,A.size()-1);
	return 0;
}
