#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Finding the missing number"<<endl;
    cout<<"enter the range "<<endl;
    cin>>n;
    int sum=0;
    for(int i=0;i<n-1;i++){
        int x;
        cout<<"enter the element in the array"<<endl;
        cin>>x;
        sum=sum+x;
    }
    int original_sum=(n*(n+1))/2;
    cout<<"the missing number is "<<original_sum-sum<<endl;
    
}