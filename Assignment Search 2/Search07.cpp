
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
    cin>>x;
    bool flas=false;
    for(int i=0;i<A.size();i++){
        if(A[i]==x){
            cout << i;
            flas=true;
            break;
        }
    }
    if(!flas) cout << "No Find";
}

int main() {
	vector<int> A;
	Input(A);
	linearSearch(A);
	return 0;
}
