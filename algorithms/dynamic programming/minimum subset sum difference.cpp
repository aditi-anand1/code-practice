/**
 * Question : Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute 
 *              difference between their sums is minimum. If there is a set S with n elements, then if we assume 
 *              Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) 
 *              should be minimum.
 * 
 * 
 * 
 * 
 * 
 * */

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int findRange(vector<int>arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum=sum+arr[i];
    }
    return sum;
}

vector<int> isSubsetSum(int sum, vector<int>arr){
    int n=arr.size();
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
    vector<int>possibleSubset;
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
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    for(int i=1;i<=sum/2;i++){
        if(dp[n][i]==true){
            possibleSubset.push_back(i);
        }
    }
    return possibleSubset;
}

int min(int a, int b){
    if(a>b)return b;
    return a;
}
int minDifferenceSubset(vector<int>arr){
    int range=findRange(arr);
    vector<int>possibleSubset=isSubsetSum(range,arr);
    int min_val=INT_MAX;
    for(int i=0;i<possibleSubset.size();i++){
        min_val=min(min_val,range-(2*possibleSubset[i]));
    }
    return min_val;
}

int main(){
    int size;
    cout<<"Size of the array"<<endl;
    cin>>size;
    vector<int>arr;
    for(int i=0;i<size;i++){
        int x;
        cout<<"Data "<<i<<endl;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"The minimum difference between two sets is ";
    cout<<minDifferenceSubset(arr);
}