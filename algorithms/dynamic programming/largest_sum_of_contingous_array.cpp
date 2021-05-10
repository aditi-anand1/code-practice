#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"KADANE'S ALGORITHM"<<endl;
    cout<<"Largest sum contiguous array"<<endl;
    vector<int>v;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"enter the element of the array"<<endl;
        int x;
        cin>>x;
        v.push_back(x);
    }
    int max_so_far=0, max_ending=0;
    for(int i=0;i<n;i++){
        max_ending=max_ending+v[i];
        if(max_ending>max_so_far){
            max_so_far=max_ending;
        }
        else if(max_ending<0){
            max_ending=0;
        }
    }
    cout<<"maximum sum of the array is"<<max_so_far<<endl;
}
