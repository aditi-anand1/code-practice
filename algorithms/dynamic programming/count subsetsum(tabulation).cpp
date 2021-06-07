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

int countSubsetSum(vector<int>arr, int sum , int n){
   vector<vector<int>>dp(n+1,vector<int>(sum+1));
   for(int i=0;i<=n;i++){
       dp[i][0]=1;
   }
   for(int i=1;i<=sum;i++){
       dp[0][i]=0;
   }
   for(int i=1;i<=n;i++){
       for(int j=1;j<=sum;j++){
           if(j<arr[i-1]){
               dp[i][j]=dp[i-1][j];
           }
           else{
               dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]]; // in subsetsum there it was or operator but in this we have + as we have to give the total number
           }                                                // so for that we need to add them.
       }
   }
   return dp[n][sum];
    
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
    cout<<"No. of subet presnt in the array is ";
    cout<<countSubsetSum(arr, sum,size);
}