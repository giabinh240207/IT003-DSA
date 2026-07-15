
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;
//code here
void Input(vector<int> &A){  
    int x;
    while(true){
        cin>>x;
        if(x==0) break;
        A.push_back(x);
    }
}
void Xuatmang(vector<int> A){
    for(int i=0;i<A.size();i++){
        cout << A[i] << " "  ;
    }
}
void insertionSort(vector<int> A){
    for(int i=1;i<A.size();i++){
        int e=A[i];
        int j=i-1;
        while(j>=0 && A[j]>e){ //sap xep tang dan
            A[j+1]=A[j];
            j--;
        } 
        A[j+1]=e;
        cout << "i=" << i<<":"<<" " << "e=" << e<<":"<< " ";
        Xuatmang(A);
        cout << "\n";
    }
}

//
int main() {
	vector<int> A;
	Input(A);
	insertionSort(A);
	return 0;
}
