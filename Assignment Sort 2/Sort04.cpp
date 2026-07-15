
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
int dem=0;
void quickSort(vector<int> &A,int left, int right){
    if(left>=right) return;
    int pivot=A[(left+right)/2];
    int i=left;
    int j=right;
    while(i<j){
        while(A[i]<pivot) i++;
        while(A[j]>pivot) j--;
        if(i<=j){
            swap(A[i],A[j]);
            i++;
            j--;
        }
    }
    dem++;
    quickSort(A,left,j);
    quickSort(A,i,right);
}
void Sort(vector<int>A){
    if(A.size()==0){
        cout<<0;
        return;
    }
    quickSort(A,0,A.size()-1);
    cout<<dem;
}

//

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
