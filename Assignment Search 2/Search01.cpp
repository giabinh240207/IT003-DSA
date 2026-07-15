
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int>&A){
    int val;
    while(true){
        cin >> val;
        if(val==0) break;
        A.push_back(val);
    }
}
void binarySearch(vector<int>A){
    int x;
    cin >> x;
    sort(A.begin(), A.end());
    for(int i=0;i<A.size();i++){
        cout << A[i] << ' ';
    }
    int soluong=0;
    int left=0;
    int right=A.size()-1;
    while(left<=right){
        soluong++;
       int mid=(left+right)/2;
       if(A[mid]<x) left=mid+1;
       else if(A[mid]>x) right = mid-1;
       else break;
    }
    cout<<"\n"<<soluong;
}

int main() {
	vector<int> A;
	Input(A);
	binarySearch(A);
	return 0;
}
