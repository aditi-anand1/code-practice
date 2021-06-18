/**
 * Question : Given two strings str1 and str2, the task is to find the length of the shortest string that has both str1 and str2 as subsequences.
 * 
 * Example : Input:   str1 = "geek",  str2 = "eke"
             Output: 5
             Explanation: String "geeke" has both string "geek" and "eke" as subsequences.
 * 
 * Algorithm : Length of the shortest supersequence  = (Sum of lengths of given two strings) - (Length of LCS of two given strings)  
**/



#include<iostream>
#include<vector>
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


int shortestSupersequence(string s1, string s2){
    int n=s1.size();
    int m=s2.size();
    int len_lcs=LCS( s1, s2, n, m);
    return n+m-len_lcs;
    
}
int main(){
    string s1,s2;
    cout<<"Enter the two strings"<<endl;
    cin>>s1>>s2;
    cout<<"Length of the shortest supersequence"<<shortestSupersequence(s1,s2);
}