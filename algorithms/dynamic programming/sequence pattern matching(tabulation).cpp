/**
 * Question : Given two strings a and b we have to check string a is present in string b.
 * 
 * Example : Input: a = "AXY"
 *                  b = "ADXCPY"
 *           Output: true

 * Algorithm : find the LCS of the strings and then if LCS matches to the size of string a then return true else false.
 * 
 * */



#include<iostream>
#include<vector>
using namespace std;
int LCS(string a, string b, int n, int m){
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
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
    return dp[n][m];
}
bool isSequencePatternMatching(string a , string b){
    int n=a.size();
    int m=b.size();
    int len=LCS(a,b,n,m);
    if(len==n){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string a;
    string b;
    cout<<"enter the pattern you want and enter the string in which you want pattern"<<endl;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    if(isSequencePatternMatching(a,b)){
        cout<<"Yes sequence pattern match "<<endl;
    }
    else{
        cout<<"No sequence pattern match "<<endl;
    }
}