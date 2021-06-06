/**
 * Question : Given weights and values of n items, put these items in a knapsack of capacity W 
 *              to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] 
 *               and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an 
 *              integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum 
 *              of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the 
 *              complete item or don’t pick it (0-1 property).
 * 
 * 
 * 
 * */

#include<iostream>
#include<vector>
using namespace std;



int max(int a, int b){
    if(a>b)return a;
    return b;
}

int knapsack(vector<int>weight,vector<int>value,int max_weight,int n){
  vector<vector<int>>dp(n+1,vector<int>(max_weight+1));

  for(int i=0;i<n+1;i++){
      for(int j=0;j<max_weight+1;j++){
          if(i==0||j==0){
              dp[i][j]=0;
          }
          else if(weight[i-1]<=j){
              dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
          }
          else{
              dp[i][j]=dp[i-1][j];
          }
      }
  }
  return dp[n][max_weight];
}

int main(){
    int size;
    cout<<"No. of choices"<<endl;
    cin>>size;
    vector<int>weight;
    vector<int>value;
    for(int i=0;i<size;i++){
        cout<<"Enter weight "<<i<<"and its corresponding value"<<endl;
        int wt,val;
        cin>>wt>>val;
        weight.push_back(wt);
        value.push_back(val);
    }
    cout<<"Capacity of bag that you can carry"<<endl;
    int max_weight;
    cin>>max_weight;

    // initializing the memoization vector to -1
     for(int i=0;i<=size;i++){
        vector<int>v;
        for(int j=0;j<=max_weight;j++){
            v.push_back(-1);
        }
        dp.push_back(v);
    }

    int profit=knapsack(weight,value,max_weight,weight.size());
    cout<<"Maximum profit is ";
    cout<<profit;
}
