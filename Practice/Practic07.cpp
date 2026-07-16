#include <iostream>
#include <vector>

using namespace std;

void Sort(vector<int> &);

int main()
{
    int n, k;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        nums.push_back(k);
    }
    Sort(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}
void quick_sort(vector<int> &arr,int left,int right){
    if(left>=right) return;
    int pivot=arr[(left+right)/2];
    int i=left;
    int j=right;
    while(i<=j){
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    quick_sort(arr,left,j);
    quick_sort(arr,i,right);
}
void Sort(vector<int>&num){
    vector<int>chan;
    vector<int>le;
    for(int a:num){
        if(a%2==0) chan.push_back(a);
        else le.push_back(a);
    }
    quick_sort(chan,0,chan.size()-1);
    quick_sort(le,0,le.size()-1);
    num.clear();
    for(int a:chan){
        num.push_back(a);
    }
    for(int b:le){
        num.push_back(b);
    }
}
	
