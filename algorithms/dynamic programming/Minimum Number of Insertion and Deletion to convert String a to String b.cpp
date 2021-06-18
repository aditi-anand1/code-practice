/**
 * Question : Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and 
 *              insert the minimum number of characters from/in str1 to transform it into str2. It could be possible 
 *              that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.
 * 
 * Example : Input : str1 = "heap", str2 = "pea" 
             Output : Minimum Deletion = 2 and Minimum Insertion = 1
             Explanation: p and h deleted from heap Then, p is inserted at the beginning One thing to note, though p was required yet
                            it was removed/deleted first from its position and then it is inserted to some other position.
                            Thus, p contributes one to the deletion_count and one to the insertion_count.
 * 
 * Algorithm : str1 and str2 be the given strings.
                m and n be their lengths respectively.
                len be the length of the longest common subsequence of str1 and str2
                minimum number of deletions minDel = m – len
                minimum number of Insertions minInsert = n – len    
 * 
 * */



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


vector<int> minNumberOfInsertionDeletion(string s1, string s2){
    int n=s1.size();
    int m=s2.size();
    int len_lcs=LCS( s1, s2, n, m);
    vector<int>v;
    v.push_back(n-len_lcs);
    v.push_back(m-len_lcs);
    return v;
    
}
int main(){
    string s1,s2;
    cout<<"Enter the two strings"<<endl;
    cin>>s1>>s2;
    vector<int>v=minNumberOfInsertionDeletion(s1,s2);
    cout<<"Minimum number of deletion "<<v[0]<<endl;
    cout<<"Minimum number of insertion "<<v[1]<<endl;
}