/**
 * Question : Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest 
 *              supersequence exists, print any one of them.
 * 
 * Example : Input: X = "AGGTAB",  Y = "GXTXAYB"
             Output: "AGXGTXAYB" OR "AGGXTXAYB" 
                OR Any string that represents shortest
                supersequence of X and Y
 * 
 * Algorithm : We start from the bottom-right most cell of the matrix and 
                push characters in output string based on below rules-

                1. If the characters corresponding to current cell (i, j) 
                    in X and Y are same, then the character is part of shortest 
                    supersequence. We append it in output string and move 
                    diagonally to next cell (i.e. (i - 1, j - 1)).

                2. If the characters corresponding to current cell (i, j)
                    in X and Y are different, we have two choices -

                    If matrix[i - 1][j] > matrix[i][j - 1],
                     we add character corresponding to current 
                    cell (i, j) in string Y in output string 
                    and move to the left cell i.e. (i, j - 1)
                    else
                    we add character corresponding to current 
                    cell (i, j) in string X in output string 
                    and move to the top cell i.e. (i - 1, j)

                3. If string Y reaches its end i.e. j = 0, we add remaining
                    characters of string X in the output string
                    else if string X reaches its end i.e. i = 0, we add 
                    remaining characters of string Y in the output string
                    
 * */



#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> LCS(string s1, string s2, int n, int m){
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
    return dp;
}


string printLongestCommonSupersequence(string s1, string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>v=LCS(s1,s2,n,m);
    string s="";
    int i=n , j=m;
   while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                s=s1[i-1]+s;
                i--;
                j--;
                
            }
            else{
                if(v[i-1][j]>v[i][j-1]){
                    s=s1[i-1] + s;
                    i--;
                }
                else {
                    s=s2[j-1]+s;
                    j--;
                }
            }
    }
    while(i>0){
        s=s1[i-1]+s;
        i--;
    }
    while(j>0){
        s=s2[j-1]+s;
        j--;
    }
    return s;
}
int main(){
    string s1, s2;
    cout<<"Enter the two strings"<<endl;
    cin>>s1>>s2;
    cout<<"Longest common supersequence : "<<printLongestCommonSupersequence(s1,s2);
   ;
}