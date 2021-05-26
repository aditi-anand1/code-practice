#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int countConstruct(string target, vector<string>given_vec){
    int len=target.size()+1;
    vector<int>ans(len,0);
    ans[0]=1;
    for( int i=0;i<len;i++){
        if(ans[i]){
            for( int j=0;j<given_vec.size();j++){
                int found=target.find(given_vec[j],i);
                if(found!=-1 && given_vec[j][0]==target[i] && found>=i )
                {
                    int index=i+given_vec[j].size();
                    ans[index]+=ans[i];
                }
            }
        }
    }
    return ans[len-1];
}
int main(){
    string target;
    cout<<"Target word:"<<endl;
    cin>>target;
    int n;
    cout<<"size of wordbank"<<endl;
    cin>>n;
    vector<string>v;
    for(int i=0;i<n;i++){
        string s;
        cout<<"Data:"<<endl;
        cin>>s;
        v.push_back(s);
    }
    cout<<countConstruct(target,v);
    
}