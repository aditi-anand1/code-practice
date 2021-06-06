/**
 * Question : Given a set of non-negative integers, 
 *              and a value sum, determine if there is a subset 
 *              of the given set with sum equal to given sum. 
 * 
 * 
 * Example : Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
             Output: True
 * */


#include<iostream>
#include<vector>
using namespace std;

bool isSubsetSum(int sum, vector<int>arr,int n){
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
             if(j<arr[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    cout<<"size of array"<<endl;
    int size;
    cin>>size;
    vector<int>arr;
    for(int i=0;i<size;i++){
        int x;
        cout<<"Enter value "<<i<<endl;
        cin>>x;
        arr.push_back(x);
    }
    int sum;
    cout<<"Enter the sum you want to make from array"<<endl;
    cin>>sum;
    if(isSubsetSum(sum,arr,arr.size())){
        cout<<"TRUE subset is present that will make the sum"<<endl;
    }
    else{
        cout<<"False subset is not present that will make the sum";
    }
}