/**
 * Question : Given a knapsack weight W and a set of n items with certain value vali and weight wti, 
 *              we need to calculate the maximum amount that could make up this quantity exactly. This 
 *              is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.
 * 
 * Algorithm : same as knapsack(0-1) only change is when we are including the item then we will not reduce n
 *              as that n indexed value can be used again.
 * 
 * Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
    Output : 100
            There are many ways to fill knapsack.
            1) 2 instances of 50 unit weight item.
            2) 100 instances of 1 unit weight item.
            3) 1 instance of 50 unit weight item and 50
                instances of 1 unit weight items.
                We get maximum value with option 2.
 * 
 */


#include<iostream>
#include<vector>
using namespace std;


int unboundedKnapsack(vector<int>weight,vector<int>value, int max_weight, int n){
    vector<vector<int>>dp(n+1,vector<int>(max_weight+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=max_weight;j++){
            if(i==0 ||j==0){
                dp[i][j]=0;
            }
            else if(weight[i-1]<=j){
                dp[i][j]=max(value[i-1]+dp[i][j-weight[i-1]],dp[i-1][j]);
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
    cout<<"Size of the weight array or value array"<<endl;
    cin>>size;
    vector<int>weight;
    vector<int>value;
    for(int i=0;i<size;i++){
        int x,y;
        cout<<"Enter weight and corresponding value"<<endl;
        cin>>x>>y;
        weight.push_back(x);
        value.push_back(y);
    }
    
    int max_weight;
    cout<<"Size of the bag"<<endl;
    cin>>max_weight;
    cout<<"Max profit"<<unboundedKnapsack(weight,value,max_weight,size);
}