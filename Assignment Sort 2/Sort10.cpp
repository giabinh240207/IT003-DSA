
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
void heapify(vector<int>&A, int heapSize, int k){
	int j=2*k+1;
	while(j<heapSize){
		if(j+1<heapSize){
			if(A[j]>A[j+1]) j++;
		}
		if(A[j]>A[k]) return;
		swap(A[j],A[k]);
		k=j;
		j=2*k+1;
	}
}
void buidHeap(vector<int>&A,int heapSize){
	int i= (heapSize-1)/2;
	while(i>=0){
		heapify(A,heapSize,i);
		i--;
	}
}
void heapSort(vector<int>&A, int heapSize){
	buidHeap(A,heapSize);
	for(int i=heapSize-1;i>0;i--){
		
		swap(A[0],A[i]);
		cout<<"N="<<heapSize<<endl;
		for(int i:A){
			cout<<i<<" ";
		}
		cout << endl;
		heapSize--;
		heapify(A,heapSize,0);
	}
}
void Sort(vector<int>A){
    if(A.size()==0){
        cout<<A.size();
        return;
    }
    heapSort(A,A.size());
}



//


int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
