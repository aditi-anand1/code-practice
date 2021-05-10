#include<iostream>
#include<vector>
#include<map>
using namespace std;

int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
    cout<<"This is the knapscak problem 0/1"<<endl;
    cout<<"enter the number of weights you want"<<endl;
    int n;
    cin>>n;
    map<int,int>bag;
    vector<int>weight;
    vector<int>profit;
    for(int i=0;i<n;i++){
        int x,y;
        cout<<"enter the weight"<<endl;
        cin>>x;
        cout<<"enter the profit corresponding to the weight"<<endl;
        cin>>y;
        bag[x]=y;
    }
    
    map<int,int>::iterator itr;
    int i=0;
    weight.push_back(0);
    profit.push_back(0);
    for(itr=bag.begin();itr!=bag.end();itr++){
        weight.push_back(itr->first);
        profit.push_back(itr->second);
    }
    
    int max_weight;
    cout<<"enter the max weight "<<endl;
    cin>>max_weight;
    
    int profit_table[n+1][max_weight+1];
    int w;
    for( i=0;i<=n;i++){
        for(w=0;w<=max_weight;w++){
            if(i==0||w==0){
                profit_table[i][w]=0;
            }
            else if(weight[i]<=w){
            profit_table[i][w]=max(profit_table[i-1][w],profit_table[i-1][w-weight[i]]+profit[i]);
            }
            else{
                profit_table[i][w]=profit_table[i-1][w];
            }
        }
    }
    i--;
    w--;
    cout<<profit_table[i][w];
    
}