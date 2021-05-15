/**
 * QUESTION- Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
 * **/

#include<bits/stdc++.h>
using namespace std;


bool subsetSumRecursion(int target_sum, vector<int>v){
    if(target_sum==0){
        return true;
    }
    if(target_sum<0){
        return false;
    }
    for( int i=0;i<v.size();i++){
        int rem=target_sum-v[i];
        if(subsetSumRecursion(rem,v)==true){
            return true;
        }
    }
    return false;
}

bool subsetSumMemoization(int target_sum, vector<int>v , map<int,bool>m){
    if(target_sum==0){
        return true;
    }
    if(target_sum<0){
        return false;
    }
    if(m.count(target_sum)){
        return m[target_sum];
    }
     for( int i=0;i<v.size();i++){
        int rem=target_sum-v[i];
        if(subsetSumMemoization(rem,v,m)==true){
            m[rem]=true;
            return true;
        }
    }
    return false;
    
}
int main(){
    cout<<"Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum"<<endl;
    cout<<"Enter target sum:"<<endl;
    int target_sum;
    cin>>target_sum;
    int n;
    cout<<"Sixe of vector:"<<endl;
    cin>>n;
    vector<int>v;
    map<int,bool>m;
    for( int i=0;i<n;i++){
        cout<<"values in vector:"<<endl;
        int x;
        cin>>x;
        v.push_back(x);
    }
    if(subsetSumRecursion(target_sum,v)){
        cout<<"Found a subset with given sum using recurion"<<endl;
    }
    else{
        cout<<"No subset with given sum using recursion"<<endl;
    }
    if(subsetSumMemoization(target_sum,v,m)){
        cout<<"Found a subset with given sum using memization"<<endl;
    }
    else{
        cout<<"No subset with given sum using memization"<<endl;
    }
    
    
}