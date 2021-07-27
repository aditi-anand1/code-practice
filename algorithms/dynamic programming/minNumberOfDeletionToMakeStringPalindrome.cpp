#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int LCS(string a,string b, int n){
    vector<vector<int>>dp(n+1,vector<int>(n+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int minNumberOfDeletionToMakeStringPalindrome(string s){
    string rev=s;
    int n=s.size();
    reverse(rev.begin(),rev.end());
    int len=LCS(s,rev,n);
     return n-len;   
}
int main(){
    string s;
    cout<<"Enter the string"<<endl;
    cin>>s;
   cout<<" Minimum number of deletion in a string to make it a palindrome is "<<minNumberOfDeletionToMakeStringPalindrome(s);
}