/**
 * Question : Given a string of size ‘n’. The task is to insert the minimum number of characters in
 *              the string so that the resultant string is a palindrome.
 * 
 * Example : Input : aebcbda
             Output : 2
            Remove characters 'e' and 'd' Resultant string will be 'abcba' which is a palindromic string
 * 
 * Same as minimum number of deletion to make string palindrome.
 * Algorihtm : 1. str is the given string.
 *              2. n length of str
                3. len be the length of the longest palindromic subsequence of str
                4. minimum number of insertion min = n – len
**/




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


int minNumberOfInsertionForPlaindromicSubsequence(string s){
    string rev=s;
    int n=s.size();
    reverse(s.begin(),s.end());
    int len=LCS(s,rev,n,n);
    return n-len;
    
}

int main(){
    string s;
    cout<<"Enter the strings"<<endl;
    cin>>s;
    cout<<"Minimum number of insertion to make string palindrome is "<<minNumberOfInsertionForPlaindromicSubsequence(s);
}