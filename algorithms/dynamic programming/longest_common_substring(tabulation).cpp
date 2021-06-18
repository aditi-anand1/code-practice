/**
 * Question : Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 
 * 
 * 
 * 
 * */


#include<iostream>
#include<vector>
using namespace std;
int longestCommonSubstring(string main_string, string sub_string, int n , int m){
   vector<vector<int>>dp(m+1,vector<int>(n+1));
    int res=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(main_string[i-1]==sub_string[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                res=max(res,dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    return res;
}


int main(){
    string main_string,sub_string;
    cout<<"Enter the string"<<endl;
    cin>>main_string;
    cout<<"String whoes longest common substring you want"<<endl;
    cin>>sub_string;
    int n=main_string.size();
    int m=sub_string.size();
    cout<<"Lenght of longest common substring is "<<longestCommonSubstring(main_string,sub_string,n,m);

}