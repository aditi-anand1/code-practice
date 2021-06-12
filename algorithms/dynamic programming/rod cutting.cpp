



#include<iostream>
#include<vector>
using namespace std;

int rodCutting(vector<int>price, int length,vector<int>len){
    vector<vector<int>>dp(length+1,vector<int>(length+1));
    for(int i=0;i<=length;i++){
        for(int j=0;j<=length;j++){
            if(j==0 || i==0){
                dp[i][j]=0;
            }
            else if(j<len[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else {
                dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
            }
        }
    }
    return dp[length][length];
}
int main(){
    int length;
    cout<<"Length of the rod"<<endl;
    cin>>length;
    vector<int>len;
    vector<int>price;
    for(int i=0;i<length;i++){
        int p;
        cout<<"price of "<<i<<" length rod"<<endl;
        cin>>p;
        price.push_back(p);
        len.push_back(i+1);
    }
    cout<<rodCutting(price,length,len);
}