#include<iostream>
#include<vector>
using namespace std;


int gridTraveller(int m,int n){
    vector<vector<int>>v(m+1,vector<int>(n+1,0));
    v[1][1]=1;
    for( int i=0;i<=m;i++){
        for( int j=0;j<=n;j++){
            if(i+1<=m){
                v[i+1][j]+=v[i][j];
            }
            if(j+1<=n){
                v[i][j+1]+=v[i][j];
            }
        }
    }
    return v[m][n];
}
int main(){
    int m,n;
    cout<<"size:"<<endl;
    cin>>m>>n;
    cout<<gridTraveller(m,n);
}