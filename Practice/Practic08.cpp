#include <iostream>
#include <fstream>

using namespace std;

struct Word {
	string Text;
	string Explanation;
};

void loadData(Word dictionary[], int &n) {
	string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        getline(cin>>ws, s);
        dictionary[i].Text = s;
        getline(cin>>ws, s);
        dictionary[i].Explanation = s;
    }
}
void saveData(Word dictionary[], int n) {
    for (int i = 0; i < n; i++) {
        cout << dictionary[i].Text << endl << dictionary[i].Explanation << endl;
    }
}
void Sort(Word [], int );

int main() {
    Word *dictionary = new Word[15000];
	int n;
	loadData(dictionary, n);
	Sort(dictionary, n);

	saveData(dictionary, n);
	delete [] dictionary;
	return 0;
}
void merge(Word ls[],Word temp[],int left,int mid , int right){
    int i=left;
    int j =mid+1;
    int k=left;
    while(i<=mid&&j<=right){
        if(ls[i].Text<=ls[j].Text){
            temp[k++]=ls[i++];  
        }
        else{
            temp[k++]=ls[j++];
        }
    }
    while(i<=mid) temp[k++]=ls[i++];
    while(j<=right) temp[k++]=ls[j++];
    for(int p=left; p<=right;p++){
        ls[p]=temp[p];
    }

}
void mergesortRange(Word ls[],Word temp[],int left,int right){
    if(left>=right) return;
    int mid=(left+right)/2;
    mergesortRange(ls,temp,left,mid);
    mergesortRange(ls,temp,mid+1,right);
    merge(ls,temp,left,mid,right);
}
void Sort(Word ls[], int n){
    Word*temp=new Word[n];
    mergesortRange(ls,temp,0,n-1);
    delete[] temp;
}