
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
void linearSearch(vector<int>A){
    int x;
    cin >> x;
    int check=0;
    for(int i=0;i<A.size();i++){
        if(A[i]!=x) continue;
        check++;
        cout << i<<" ";
    }
    if(check==0) cout << "No Find";
}

int main() {
	vector<int> A;
	Input(A);
	linearSearch(A);
	return 0;
}
