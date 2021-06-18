/**
 * Question : Given a sequence, find the length of the longest palindromic subsequence in it.
 * Example : Input =" agbcba"
 *           Output= 5
 * 
 * Algorithm : LPS (a) = LCS(a, reverse(a))
 * 
 * */





#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int n, int m){
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


int longestPlaindromicSubsequence(string s){
    string rev=s;
    int n=s.size();
    reverse(s.begin(),s.end());
    int len=LCS(s,rev,n,n);
    return len;
    
}
int main(){
    string s;
    cout<<"Enter the strings"<<endl;
    cin>>s;
    cout<<"Length of longest plaindromic subsequence "<<longestPlaindromicSubsequence(s);
}