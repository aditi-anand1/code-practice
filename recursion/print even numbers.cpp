#include<iostream>
using namespace std;

void is_even(int i,int n){
    if(i>=n){
    return;
        
    }
    else{
         if(i%2==0){
        cout<<i<<" ";
    }
    i++;
    return is_even(i,n);
        
    }
}
int main(){
    int n,i=0;
    cout<<"this will print all the even numbers between the till the number you give"<<endl;
    cin>>n;
    is_even(i,n);
    
}