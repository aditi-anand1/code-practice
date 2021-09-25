#include<iostream>
#include<vector>
using namespace std;

void generate(vector<string> &v,string s,int open, int close, int max){
    if(s.size()==2*max){
        v.push_back(s);
    }
    if(open<max){
        s=s+"(";
        generate(v,s,open+1,close,max);
        s.pop_back();
    }
    if(close<open){
        s=s+")";
       generate(v,s,open,close+1,max);
        s.pop_back(); 
    }
}
int main(){
    int n;
    cout<<"size:"<<endl;
    cin>>n;
    string s="";
    vector<string>v;
    generate(v,s,0,0,n);
    //cout<<v.size();
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
