/**
 * Question : Given an array  and a differnce we have to tell the number of subsets present whoes difference is equal to the given diff
 * Samples Case : arr[] : 1,2,3,1
 *                 diff : 1
 *                 O/P : 3
 * so we have to divide it into 2 subset whoes diff is diff so
 *  s1-s1=diff----1
 * and we know that sum of both subset will be sum of the array
 * s1+s2=sum(arr)----2
 * adding 1 and 2
 * 2*s1= diff +sum(arr)
 * s1=(diff+sum(arr))/2
 *then we will just count the number of s1 present in the subset so for that we will use count subset sum.
 * */ 


#include<iostream>
#include<vector>
using namespace std;


//to fine the sum of the array
int sumOfArray(vector<int>arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum=sum+arr[i];
    }
    return sum;
}

//To count the number of subset present with teh given sum in the array
int countOfSubsetSum(int sum , vector<int>arr){
    int n=arr.size();
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
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}


// to give the number of subset with teh given diff
int countSubsetOfGivenDiff(int diff, vector<int>arr){
    int sum_arr=sumOfArray(arr);
    int sum=(diff+sum_arr)/2;
    int count=countOfSubsetSum(sum,arr);
    return count;
    
}

int main(){
    int size;
    cout<<"Size of array"<<endl;
    cin>>size;
    vector<int>arr;
    for(int i=0;i<size;i++){
        int x;
        cout<<"Data "<<i<<endl;
        cin>>x;
        arr.push_back(x);
    }
    int diff;
    cout<<"Difference :"<<endl;
    cin>>diff;
    cout<<"Number of subset present whoes diff is "<<diff<<" is ";
    cout<<countSubsetOfGivenDiff(diff, arr);
}