#include<iostream>
#include<vector>
using namespace std;

vector<int>howsum(int target, vector<int>given_vector){
    vector<vector<int>>ans_vector;
    for(int i=0;i<=target;i++){
        vector<int>inside;
        inside.push_back(0);
        ans_vector.push_back(inside);
    }
    ans_vector[0].pop_back();
    ans_vector[0].push_back(1);
    for( int i=0;i<target;i++){
        if(ans_vector[i][0]>0){
            for( int j=0;j<given_vector.size();j++){
                int x=i+given_vector[j];
                if(x<=target){
                    ans_vector[x].pop_back();
                    if(i>0)ans_vector[x]=ans_vector[i];
                    ans_vector[x].push_back(given_vector[j]);
                    
                }
            }
        }
    }
    return ans_vector[target];
}
int main(){
    int target;
    cout<<"Tragetsum:"<<endl;
    cin>>target;
    int size;
    cout<<"size of vector"<<endl;
    cin>>size;
    vector<int>given_vector;
    for( int i=0;i<size;i++){
        int x;
        cout<<"vector value"<<endl;
        cin>>x;
        given_vector.push_back(x);
    }
    vector<int>ans=howsum(target,given_vector);
    cout<<"how to calculate the target value"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}