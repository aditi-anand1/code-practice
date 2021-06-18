/**
 * Question : Given two strings a and b we have to check string a is present in string b.
 * 
 * Example : Input: a = "AXY"
 *                  b = "ADXCPY"
 *           Output: true

 * 
 * 
 * */



#include<iostream>
using namespace std;
bool check(string a , string b, int n , int m){
    if(n==0){
        return true;
    }
    if(m==0){
        return false;
    }
    if(a[n-1]==b[m-1]){
        return check(a,b,n-1,m-1);
    }
    else{
        return check(a,b,n,m-1);
    }
}
int main(){
    string a;
    string b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    if(check(a,b,n,m)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}