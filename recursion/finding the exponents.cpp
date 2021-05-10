#include<iostream>
using namespace std;

// using DP
int expo( int a, int b){
    if(b==1){
        return a;
    }
    int res=expo(a,b/2);
    res=res*res;
    if(b%2!=0){
        return res*a;
    }
    else{
    return res;
    }
    
}
// using nromal apporach
int expo_norml( int a, int b){
    if(b==0){
        return 1;
    }
    return expo_norml(a,b-1);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<"using divide and conquer"<<endl;
    cout<<expo(a,b);
    cout<<endl;
    cout<<" using normal approach"<<endl;
    cout<<expo_norml(a,b);
    
}