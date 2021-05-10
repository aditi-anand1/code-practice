#include<iostream>
#include<vector>
using namespace std;

void subset(vector<int>v, int i, int n, string s){
   if(i==n){
       cout<<"[ "<<s<<"] ";
       return ;
   } 
   subset(v, i+1, n, s);
   subset(v, i+1, n, s + to_string(v[i]) + " ");
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
    string s="";
    subset(v, 0, n, s);
}