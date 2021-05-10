#include<iostream>
using namespace std;
void sum(int i,int n){
    if(i>n){
        return;
    }
    else{
    cout<<i+i+1<<" ";
    i++;
    return sum(i,n);
    }
    
}
int main(){
    int n,i=0;
    cout<<"this will print the sum of n numbers"<<endl;
    cin>>n;
   sum(i,n);
}
