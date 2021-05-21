/**
 * 
 * Question : Factorial of a non-negative integer, is multiplication of all integers smaller than 
 *              or equal to n. For example factorial of 6 is 6*5*4*3*2*1 which is 720
 * */



#include<iostream>
#include<vector>
using namespace std;

// using recusrion 
long long method1(long long n){
    if(n<=1){
        return 1;
    }
    return method1(n-1)*n;
}


//using tabulation storing factorial in vector and using the previous factorial to calculate next.
long long method2(long long n){
    vector<int>v(n+1,0);
    v[0]=1;
    
    for( int i=1;i<=n;i++){
        v[i]=v[i-1]*i;
    }
    return v[n];
}


//  Using iterative method to calculate the factorial but it wont save the other factoorial
long long method3(long long n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}


//Using Ternary operator: if(condition) ? true : false;
long long method4(long long n){
    return (n<=1)?1:method4(n-1)*n;
}

int main(){
    long long n;
    cout<<"Number for factorial"<<endl;
    cin>>n;
    cout<<method1(n)<<endl;
    cout<<method2(n)<<endl;
    cout<<method3(n)<<endl;
    cout<<method4(n)<<endl;
}