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
vector<vector<int>>dp; // global vector for memoization


int max(int a, int b){
    if(a>b)return a;
    return b;
}
int knapsack(vector<int>weight,vector<int>value,int max_weight,int n){
    if(n==0 || max_weight==0){  // Base Case
        return 0;
    }
    
     if(dp[n][max_weight]!=-1){ //before calling the recusrion we will check whether the value exist in tthe table or not
        return dp[n][max_weight];       // if value is there we will return the value without calling the recusrion
    }

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    if(weight[n-1]<=max_weight){
        dp[n][max_weight]= max(value[n-1]+knapsack(weight,value,max_weight-weight[n-1],n-1) //storing the value in the matrix
                                , knapsack(weight,value,max_weight,n-1));
        return dp[n][max_weight];
    }

     // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    else if(weight[n-1]>max_weight){
        dp[n][max_weight]= knapsack(weight,value,max_weight,n-1);
        return dp[n][max_weight];
    }
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
