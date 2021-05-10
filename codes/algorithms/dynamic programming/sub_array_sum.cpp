#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    vector<int>v;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter the element"<<endl;
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"enter the sum"<<endl;
    int sum;
    cin>>sum;
    int r=0;
    int start=0,cal_sum=v[0],i;
    for(i=1;i<n;i++){
        cal_sum=cal_sum+v[i];
        while(cal_sum>sum&&start<i-1){
        cal_sum=cal_sum-v[start];
        start++;
        }
        if(cal_sum==sum){
            r=2;
            break;
        }
    }
    if(r){
        cout<<"sub array is from index "<<start<< " to "<<i<<endl;
    }
    else{
        cout<<"sub array not found"<<endl;
    }
}