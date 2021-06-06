/**
 * Question : Partition problem is to determine whether a given set can be partitioned
 *               into two subsets such that the sum of elements in both subsets is the same.
 * 
 * Sample Test Case: arr[] = {1, 5, 11, 5}
                    Output: true 
                    The array can be partitioned as {1, 5, 5} and {11}

 *
    Algorithm : 1) Calculate sum of the array. If sum is odd, there can not be two subsets with equal sum, so return false. 
                2) If sum of array elements is even, calculate sum/2 and find a subset of array with sum equal to sum/2. 
 * */




#include<iostream>
#include<vector>
using namespace std;

//issubset sum is find using tabulation
bool isSubsetSum(int sum, vector<int>arr, int n){
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
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
    return dp[n][sum];
}

bool isEqualSumPartition(vector<int>arr){
    int len=arr.size();
    int sum=0;
    for(int i=0;i<len;i++){
        sum=sum+arr[i];
    }
    if(sum%2==0){
       if(isSubsetSum( sum/2,arr,arr.size())){
           return true;
       } 
       else{
          return false; 
       }
    }
    else{
        return false;
    }
}
int main(){
    int size;
    cout<<"Size of an array"<<endl;
    cin>>size ;
    vector<int>arr;
    for(int i=0;i<size;i++){
        int x;
        cout<<"Enter value "<<i<<endl;
        cin>>x;
        arr.push_back(x);
    }
    if(isEqualSumPartition(arr)){
        cout<<"True equal sum partition is possible the given array"<<endl;
    }
    else{
        cout<<"False equal sum partitionis not possible for the given array"<<endl;
    }
}