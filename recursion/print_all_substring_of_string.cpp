#include<iostream>
#include<vector>
using namespace std;

vector<string>s;
void print_substring(int i ,int n ,int j, string original, string sub){
    if(i==n){
        return ;
    }
    if(j<=n){
        if(!sub.empty()){
            s.push_back(sub);
        }
        print_substring(i,n,j+1,original,sub+original[j]);
        
    }
    else{
        sub="";
        print_substring(i+1,n,i+1,original,sub);
    }
}
int main(){
    string original;
    cout<<"Enter the string whoes substring you want"<<endl;
    cin>>original;
    string sub="";
    print_substring(0,original.size(),0,original,sub);
    for( int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    
}