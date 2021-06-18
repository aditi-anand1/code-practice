/**
 * Question : To print the longest common subsequence between 2 string.
 * 
 *Algorithm : 1) Construct L[m+1][n+1] using the steps discussed in previous post.
                2) The value L[m][n] contains length of LCS. Create a character array lcs[] of length equal to the length of lcs plus 1 (one extra to store \0).
                2) Traverse the 2D array starting from L[m][n]. Do following for every cell L[i][j]
                    a) If characters (in X and Y) corresponding to L[i][j] are same (Or X[i-1] == Y[j-1]), then include this character as part of LCS.
                    b) Else compare values of L[i-1][j] and L[i][j-1] and go in direction of greater value.
 * */



#include<iostream>
#include<vector>
using namespace std;

//to create the longest common subsequence table
vector<vector<int>>tableForLCS(string main_string,string sub_string ,int n , int m){
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(main_string[i-1]==sub_string[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp;
}

string printLCS(string main_string, string sub_string,int n, int m){
    string s="";
    int i=n,j=m;
    vector<vector<int>>dp=tableForLCS(main_string,sub_string,n,m);
    while(i>0 &&j>0){
        if(main_string[i-1]==sub_string[j-1]){
            s=main_string[i-1]+s;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    return s;
}
int main(){
    string main_string,sub_string;
    cout<<"Enter the 1st string"<<endl;
    cin>>main_string;
    cout<<"Enter the 2nd string"<<endl;
    cin>>sub_string;
    int n=main_string.size();
    int m=sub_string.size();
    cout<<printLCS(main_string,sub_string,n,m);
}
