/**
 * Question : Given two sequences, find the length of longest subsequence present in both of them. 
 *              A subsequence is a sequence that appears in the same relative order, but not necessarily
 *               contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”
 * 
 * 
 * 
 * */



#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>dp;
int longestCommonSubsequence(string main_string , string sub_string, int n, int m){
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            
            if(i==0 ||j==0){
                dp[i][j]=0;
            }
  
             else if(main_string[i-1]==sub_string[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string main_string;
    cout<<"Enter the string"<<endl;
    cin>>main_string;
    string sub_string;
    cout<<"Enter the string whoes longest subsequence you want to find"<<endl;
    cin>>sub_string;
    int n=main_string.size();
    int m=sub_string.size();
 
    cout<<"Length of longest common subsequence is "<<longestCommonSubsequence(main_string,sub_string,n,m);
}