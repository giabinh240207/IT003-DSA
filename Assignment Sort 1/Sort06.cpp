
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;
// code here
void Input(vector <int> &A){
    int x;
    while(true){
        cin>>x;
        if(x==0) break;
        A.push_back(x);
    }
}
void Output(vector<int> A){
    for(int i=0;i<A.size();i++){
        cout << A[i] <<" ";
    }
}
void selectionSort(vector<int> &A){
    for(int i=0;i<A.size()-1;i++){
        int min=i;
        for(int j=i+1;j<A.size();j++){
            if(A[j]<A[min]) min = j; //tang dan
        }
        swap(A[i],A[min]);
        cout << "i="<<i<<":"<<" ";
        Output(A);
        cout << "\n";
    }

}
//
int main() {
	vector<int> A;
	Input(A);
	selectionSort(A);
	return 0;
}
