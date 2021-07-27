/**
 * Question: Given a string, a partitioning of the string is a palindrome partitioning 
 *              if every substring of the partition is a palindrome.
 * 
 * Sample:  Input : str = “geek” 
            Output : 2 
            We need to make minimum 2 cuts, i.e., “g ee k”
 * 
 * 
 * Algorithm:  i is the starting index and j is the ending index. i must be passed as 0 and j as n-1
                minPalPartion(str, i, j) = 0 if i == j. // When string is of length 1.
                minPalPartion(str, i, j) = 0 if str[i..j] is palindrome.

                If none of the above conditions is true, then minPalPartion(str, i, j) can be 
                calculated recursively using the following formula.
                minPalPartion(str, i, j) = Min { minPalPartion(str, i, k) + 1+ minPalPartion(str, k+1, j) } where k varies from i to j-1
 * 
 * 
 * */


#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}
bool isPlaindrome(string s, int i ,int j){
    
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int minPalindromePartition(string s ,int i, int j){
    if(i>=j){
        return 0;
    }
    if(isPlaindrome(s,i,j)==true){
        return 0;
    }
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
        int temp= 1+minPalindromePartition(s,i,k)+minPalindromePartition(s,k+1,j);
        mn=min(mn,temp);
    }
    return mn;
}
int main(){
    string s;
    cout<<"string"<<endl;
    cin>>s;
    int n=s.size()-1;
    cout<<minPalindromePartition(s,0,n);
}