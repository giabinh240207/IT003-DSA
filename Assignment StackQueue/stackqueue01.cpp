
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define MAX 300
//code here
#include<stack>
void StringReverse(string& s){
    stack<string> str;
    string term;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            str.push(term);
            str.push(" ");
            term="";
        }
        else term+=s[i];
    }
    str.push(term);
    s="";
    while(!str.empty()){
        s+=str.top();
        str.pop();
    }

}

//
int main () {
    string s;

    getline(std::cin, s);	//Nhap chuoi s

    if(s.empty() == true)
        cout << "Chuoi rong." << endl;
    else {
        StringReverse(s);
        cout << s << endl;

    }

    return 0;
}
