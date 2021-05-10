#include<iostream>
#include<map>
using namespace std;
int main(){
    cout<<"enter the first string"<<endl;
    string s1;
    cin>>s1;
    cout<<"enter the second string"<<endl;
    string s2;
    cin>>s2;
    map<char,int>m;
    for(int i=0;i<s1.size();i++){
        m[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++){
        if(m[s2[i]]>0){
            m[s2[i]]--;
        }
    }
    map<char,int>::iterator itr;
    for(itr=m.begin();itr!=m.end();itr++){
        if(itr->second>0||itr->second<0){
            cout<<"String is not permutation of the other"<<endl;
            break;
        }
    }
    if(itr==m.end()){
        cout<<"Both the string are in permutations"<<endl;
    }
    
}