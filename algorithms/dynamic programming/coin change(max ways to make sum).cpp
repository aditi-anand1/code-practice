#include<iostream>
#include<vector>
using namespace std;

int maxWaysToMakeSum(int sum, vector<int>coins){
    int n=coins.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<coins[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int sum;
    cout<<"Sum :"<<endl;
    cin>>sum;
    int size;
    cout<<"Size of array"<<endl;
    cin>>size;
    vector<int>coins;
    for(int i=0;i<size;i++){
        int x;
        cout<<"Value of coin"<<endl;
        cin>>x;
        coins.push_back(x);
    }
    cout<<"Maximum ways to make the changes of the sum is "<<maxWaysToMakeSum(sum,coins);
    
}