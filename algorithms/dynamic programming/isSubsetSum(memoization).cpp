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
vector<vector<int>>dp; // global vector for memoization

int isSubsetSum(int sum, vector<int>arr,int n){
    if(sum==0){
        return 1;
    }
     else if(sum<0||n==0){
        return 0;
    }
    else if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    else if(sum>=arr[n-1]){
        dp[n][sum]=isSubsetSum(sum-arr[n-1],arr,n-1)||isSubsetSum(sum,arr,n-1);
        return dp[n][sum];
    }
    else{
        dp[n][sum]= isSubsetSum(sum,arr,n-1);
        return dp[n][sum];
    }
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
    for(int i=0;i<size+1;i++){
        vector<int>v;
        for(int j=0;j<sum+1;j++){
            v.push_back(-1);
        }
        dp.push_back(v);
    }
    if(isSubsetSum(sum,arr,arr.size())){
        cout<<"TRUE subset is present that will make the sum"<<endl;
    }
    else{
        cout<<"False subset is not present that will make the sum";
    }
}