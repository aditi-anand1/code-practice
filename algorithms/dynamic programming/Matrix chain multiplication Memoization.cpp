
/**
 * Question: Given an array p[] which represents the chain of matrices such that the ith matrix Ai is of 
 *              dimension p[i-1] x p[i]. We need to write a function MatrixChainOrder() 
 *              that should return the minimum number of multiplications needed to multiply the chain.
 * 
 * Sample : Input: p[] = {40, 20, 30, 10, 30}   
            Output: 26000  
            There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
            Let the input 4 matrices be A, B, C and D.  The minimum number of 
            multiplications are obtained by putting parenthesis in following way
            ( A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
 * 
 *Algorithm: A simple solution is to place parenthesis at all possible places, calculate the cost for each placement 
                and return the minimum value. In a chain of matrices of size n, we can place the first set of parenthesis 
                in n-1 ways. For example, if the given chain is of 4 matrices. let the chain be ABCD, then there are 3 ways 
                to place first set of parenthesis outer side: (A)(BCD), (AB)(CD) and (ABC)(D). So when we place a set of 
                parenthesis, we divide the problem into subproblems of smaller size. Therefore, the problem has optimal 
                substructure property and can be easily solved using recursion.Minimum number of multiplication needed 
                to multiply a chain of size n = Minimum of all n-1 placements (these placements create subproblems of 
                smaller size)
**/

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
int min(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}
int solve(vector<int>arr, int i, int j){
    if(i==j){
        return 0;
    }
    int mn=INT_MAX;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    for(int k=i;k<=j-1;k++){
        int tempAns= solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        mn=min(mn,tempAns);
    }
    dp[i][j]= mn;
    return dp[i][j];
}

int main()
{
    int n;
    cout<<"size:"<<endl;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cout<<"Array values"<<endl;
        cin>>x;
        arr.push_back(x);
    }
    for(int i=0;i<n;i++){
        vector<int>v;
        for(int j=0;j<n;j++){
            v.push_back(-1);
        }
        dp.push_back(v);
    }
    int i=1;
    int j=n-1;
    cout<<"Minimum number of multiplications needed to multiply the chain "<<solve(arr,i,j);
    return 0;
}
