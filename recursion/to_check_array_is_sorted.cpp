#include<iostream>
#include<vector>
using namespace std;
void check(int i,int n, vector<int>v){
    //cout<<i;
    if(i==n-1){
        cout<<"YES";
        return ;
    }
    if(v[i]>v[i+1]){
        cout<<"NO";
        return ;
    }
    check(i+1,n,v);
}
int main(){
    vector<int>v;
    int n;
    cin>>n;
    for( int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    check(0,n,v);
}