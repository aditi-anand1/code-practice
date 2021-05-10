#include<bits/stdc++.h>
#include<vector>
using namespace std;

int coin_changes(int amount, vector<int>coin_changes){
    int i=0;
    int counting=0, number;
    while(amount){
        number=amount/coin_changes[i];
        amount=amount-(number*coin_changes[i]);
        counting=counting+number;
        i++;
    }
    return counting;
}
int main(){
    cout<<" Greedy Algorithm to find Minimum number of Coins"<<endl;
    int n;
    cout<<" enter the number of denimination of the coin"<<endl;
    cin>>n;
    vector<int>coin_variation;
    for( int i=0;i<n;i++){
        int t;
        cout<<"the coin denominations"<<endl;
        cin>>t;
        coin_variation.push_back(t);
    }
    
    sort(coin_variation.begin(),coin_variation.end(),greater<int>());  // sorting the vector in decending order
    for(int i=0;i<n;i++){
        cout<<coin_variation[i]<<" ";
    }
    int amount;
    cout<<"enter the amount whoes minimum number ofchange we want"<<endl;
    cin>>amount;
    int x=coin_changes(amount,coin_variation);
    cout<<x;
    
}
