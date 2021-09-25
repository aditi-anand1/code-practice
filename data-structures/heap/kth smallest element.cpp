/**
 *Question: Given an array and a number k where k is smaller than the size of the array, 
        we need to find the k’th smallest element in the given array. It is given that all array elements are distinct. 
 * 
 * 
 * */


#include<bits/stdc++.h>
using namespace std;

int kthSmallestValue(int k, vector<int>v){
    priority_queue<int>q;
    int n=v.size();
    for(int i=0;i<n;i++){
        q.push(v[i]);
        if(q.size()>k){
            q.pop();
        }
    }
    return q.top();
}
int main(){
    
    int n;
    cout<<"size:"<<endl;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cout<<"data:"<<endl;
        cin>>x;
        v.push_back(x);
    }
    cout<<"k value:"<<endl;
    int k;
    cin>>k;
    cout<<"given vector:"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<kthSmallestValue(k,v);
}
   