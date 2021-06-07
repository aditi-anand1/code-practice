/**
 * Question : Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X
 * 
 * Sample test case: Input: arr[] = {2, 3, 5, 6, 8, 10}, X = 10 
                     Output: 3 
                     Explanation: All possible subsets with sum 10 are {2, 3, 5}, {2, 8}, {10}
 * 
 * 
 * 
 * */

#include<iostream>
#include<vector>
using namespace std;

//same code as issubset sum only differnce is functon will return int here.

vector<vector<int>>dp;
int countSubsetSum(vector<int>arr, int sum , int n){
    if(sum==0)return 1;
    
    if(sum<0 ||n==0)return 0;
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(sum>=arr[n-1]){
        dp[n][sum]= countSubsetSum(arr,sum-arr[n-1],n-1)+countSubsetSum(arr,sum ,n-1);
        return dp[n][sum];

    }
    else{
        dp[n][sum]= countSubsetSum(arr,sum ,n-1);
        return dp[n][sum];
    }
}

int main(){
    int size;
    cout<<"Size of the array"<<endl;
    cin>>size;
    vector<int>arr;
    for(int i=0;i<size;i++){
        int x;
        cout<<"Enter the value "<<i<<endl;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"Target sum"<<endl;
    int sum;
    cin>>sum;
        for(int i=0;i<=size;i++){
        vector<int>v;
        for(int j=0;j<=sum;j++){
            v.push_back(-1);
        }
        dp.push_back(v);
    }
    cout<<"No. of subet presnt in the array is ";
    cout<<countSubsetSum(arr, sum,size);
}