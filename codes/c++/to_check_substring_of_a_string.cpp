#include<iostream>
using namespace std;

int main(){
    string original;
    cout<<"Enter the string "<<endl;
    cin>>original;
    string substring;
    cout<<"Enter the substring which you want to check"<<endl;
    cin>>substring;
    int sub_moving=0;
    for( int i=0;i<original.size();i++){
        if(original[i]==substring[sub_moving]){
             sub_moving++;
        }
        else{
            sub_moving=0;
        }
        if(sub_moving>=substring.size()){
            cout<<"Yes it is substring"<<endl;
            return 0;
        }
    }
    cout<<"No";
    
}