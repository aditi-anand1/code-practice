/**
 * To check whether we can construct the given target string with the goven word bank or not
 * */

#include<bits/stdc++.h>
using namespace std;


bool canConstructRecursion(string target, vector<string>v){
    if(target==""){
        return true;
    }
    for( int i=0;i<v.size();i++){
        if(target.find(v[i])==0){
            int n=v[i].size();
            string s=target.substr(n);
            if(canConstructRecursion(s,v)){
                return true;
            }
        }
    }
    return false;
    
}

bool canConstructMemoization(string target, vector<string>v, map<string,bool>m){
    if(m.count(target)){
        return m[target];
    }
    if(target==""){
        return true;
    }
    for( int i=0;i<v.size();i++){
        if(target.find(v[i])==0){
            int n=v[i].size();
            string s=target.substr(n);
            if(canConstructMemoization(s,v,m)){
                m[target]=true;
                return true;
            }
        }
    }
    return false;
}
int main(){
    string target;
    cout<<"Target string:"<<endl;
    cin>>target;
    int size;
    cout<<"Size of word bank:"<<endl;
    cin>>size;
    vector<string>v;
    map<string,bool>m;
    for( int i=0;i<size;i++){
        string s;
        cout<<"data:"<<endl;
        cin>>s;
        v.push_back(s);
    }
    
    if(canConstructRecursion(target,v)){
        cout<<"Yes given target can be constructed using word bank using recursion"<<endl;
    }
    else{
        cout<<"No given target can be constructed using word bank recursion"<<endl;

    }
    if(canConstructMemoization(target,v,m)){
        cout<<"Yes given target can be constructed using word bank using Memoization"<<endl;
    }
    else{
        cout<<"No given target can be constructed using word bank Memoization"<<endl;

    }
    
}