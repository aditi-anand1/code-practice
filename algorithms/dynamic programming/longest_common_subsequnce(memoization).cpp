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
    if(n==0 ||m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    else if(main_string[n-1]==sub_string[m-1]){
        dp[n][m]=1+longestCommonSubsequence(main_string,sub_string,n-1,m-1);
        return dp[n][m];
    }
    else{
        dp[n][m]= max(longestCommonSubsequence(main_string,sub_string,n,m-1),longestCommonSubsequence(main_string,sub_string,n-1,m));
        return dp[n][m];
    }
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
    for(int i=0;i<=n;i++){
        vector<int>v;
        for(int j=0;j<=m;j++){
            v.push_back(-1);
        }
        dp.push_back(v);
    }
    cout<<"Length of longest common subsequence is "<<longestCommonSubsequence(main_string,sub_string,main_string.size(),sub_string.size());
}