/**
 * Question: Given the number of possible ways to construct the given string from the word bank:
 * */
#include<bits/stdc++.h>
using namespace std;


int countConstructRecursion(string target, vector<string>v){
    if(target==""){
        return 1;
    }
    int total=0;
    for( int i=0;i<v.size();i++){
        if(target.find(v[i])==0){
            int n=v[i].size();
            string s=target.substr(n);
        int count=countConstructRecursion(s,v);
            total=total+count;
            
        }
    }
    return total;
    
}


int countConstructMemoization(string target, vector<string>v, map<string ,int>m){
    if(m.count(target)){
        return m[target];
    }
    if(target==""){
        return 1;
    }
    int total=0;
    for( int i=0;i<v.size();i++){
        if(target.find(v[i])==0){
            int n=v[i].size();
            string s=target.substr(n);
        int count=countConstructMemoization(s,v,m);
            total=total+count;
            
        }
    }
    m[target]=total;
    return total;
    
}


 
int main(){
    string target;
    cout<<"Target string:"<<endl;
    cin>>target;
    int size;
    cout<<"Size of word bank:"<<endl;
    cin>>size;
    vector<string>v;
    map<string,int>m;
    for( int i=0;i<size;i++){
        string s;
        cout<<"data:"<<endl;
        cin>>s;
        v.push_back(s);
    }
 int n=countConstructRecursion(target,v);
 cout<<"The number of ways you can construct the given string using recusrion is: "<<n<<endl;
 n=countConstructMemoization(target,v,m);
 cout<<n<<endl;
  cout<<"The number of ways you can construct the given string using memoization is: "<<n<<endl;

   
    
}