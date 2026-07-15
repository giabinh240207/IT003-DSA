//code here
#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

void decimal_to_binary(int n){
    if(n==0){
        cout<<n;
        return;
    } 
    stack<int> str;
    while(n!=0){
        str.push(n%2);
        n=n/2;
    }
    while(!str.empty()){
        cout<<str.top();
        str.pop();
    }
}



//
int main() {
    int n;
    cin >> n;
    decimal_to_binary(n);
    return 0;
}
