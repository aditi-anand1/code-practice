/**
 * Question : Given a string, find the length of the longest repeating subsequence such that the two subsequences 
 *              don’t have same string character at the same position, i.e., any i’th character in the two subsequences 
 *              shouldn’t have the same index in the original string.
 * 
 * Example : Input: str = "aab"
             Output: 1
                The two subssequence are 'a'(first) and 'a'(second). 
                Note that 'b' cannot be considered as part of subsequence 
                as it would be at same index in both.           
 * 
 * 
 * */



#include<iostream>
#include<vector>
using namespace std;
int longestRepeatingSubsequence(string a, int n){
    string b=a;
    vector<vector<int>>dp(n+1,vector<int>(n+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1] && i!=j){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main(){
    string s;
    cout<<"Enter the string"<<endl;
    cin>>s;
   cout<<"Length longest repeating subsequence is "<<longestRepeatingSubsequence(s,s.size());
}