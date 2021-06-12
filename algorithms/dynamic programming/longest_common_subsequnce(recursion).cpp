/**
 * Question : Given two sequences, find the length of longest subsequence present in both of them. 
 *              A subsequence is a sequence that appears in the same relative order, but not necessarily
 *               contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”
 * 
 * 
 * 
 * */


#include<iostream>
using namespace std;

int longestCommonSubsequence(string main_string , string sub_string, int n, int m){
    if(n==0 ||m==0){
        return 0;
    }
    else if(main_string[n-1]==sub_string[m-1]){
        return 1+longestCommonSubsequence(main_string,sub_string,n-1,m-1);
    }
    else{
        return max(longestCommonSubsequence(main_string,sub_string,n,m-1),longestCommonSubsequence(main_string,sub_string,n-1,m));
    }
}
int main(){
    string main_string;
    cout<<"Enter the string"<<endl;
    cin>>main_string;
    string sub_string;
    cout<<"Enter the string whoes longest subsequence you want to find"<<endl;
    cin>>sub_string;
    cout<<"Length of longest common subsequence is"<<longestCommonSubsequence(main_string,sub_string,main_string.size(),sub_string.size());
}