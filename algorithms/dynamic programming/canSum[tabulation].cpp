/**
 * Question : Can we construct the target sum with the given array using tabulation
 * */

#include<iostream>
#include<vector>
using namespace std;


bool canSum( int target, vector<int>v){
    vector<bool>info(target+1,false);
    info[0]=true;
    for( int i=0;i<info.size();i++){
        if(info[i]==true){
            int j=0;
            while(j<v.size()){
                int k=i+v[j];
                if(k<info.size()){
                    info[k]=true;
                }
                j++;
            }
        }
    }
    return info[target];
}
int main(){
    int targetsum;
    cout<<"targetsum:"<<endl;
    cin>>targetsum;
    vector<int>v;
    cout<<"size of vector"<<endl;
    int n;
    cin>>n;
    for( int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    if(canSum(targetsum,v)){
        cout<<"Yes its possible to generate the target sum"<<endl;
    }
    else{
        cout<<"No its possible to generate the target sum"<<endl;
        
    }
}