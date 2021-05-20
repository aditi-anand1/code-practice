/**
 *  Question : Given an integer, write a function that returns true if the given number is palindrome, else false.
 *              For example, 12321 is palindrome, but 1451 is not palindrome.
 * */



#include<bits/stdc++.h>
#include<vector>
using namespace std;


//Using string() method : iterating string from both the end.

bool method1(long long n){
    string s=to_string(n);
    int end=s.size()-1;
    int start=0;
    while(start<=end){
        if(s[start]!=s[end])return false;
        start++;
        end--;
    }
    return true;
}


// By digit extraction and storing in a vector and iterating vector from start and end.
bool method2(long long n){
    vector<int>v;
    while(n>0){
        int rem=n%10;
        v.push_back(rem);
        n=n/10;
    }
    int end=v.size()-1;
    int start=0;
    while(start<=end){
        if(v[start]!=v[end])return false;
        start++;
        end--;
    }
    return true;
}


//Using string() method : By reversing the string and comparing with original one.

bool method3(long long n){
    string s=to_string(n);
    string rev=s;
    reverse(s.begin(),s.end());
    if(s==rev)return true;
    return false;
    
}


//By reversing the digits of number and comparing it with the original one.
bool method4(long long n){
    long long temp=0 , curr=n;
    
    while(n>0){
        int rem=n%10;
        temp=temp*10+rem;
        n=n/10;
    }
    if(curr==temp)return true;
    return false;
}
string output(bool res){
     if(res){
        return "Yes the integer is palindrome";
    }
    else{
        return "No the integer is palindrome";
    }
}
int main(){
    long long n;
    cout<<"Enter the integer:"<<endl;
    cin>>n;
    cout<<output(method1(n))<<endl;
    cout<<output(method2(n))<<endl;
    cout<<output(method3(n))<<endl;
    cout<<output(method4(n))<<endl;
   
}
