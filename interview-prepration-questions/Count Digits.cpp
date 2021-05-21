/**
 * Question : Count the number of digits in a long integer entered by a user.
 * */


#include<iostream>
#include<math.h>
using namespace std;


//We can convert the number into a string and then find the length
//   of the string to get t                             he number of digits in the original number.
int method1(long long n){
    string s=to_string(n);
    return s.size();
}


//Simple Iterative Solution 

int method2(long long n){
    int i=0;
    while(n>0){
        n=n/10;
        i++;
    }
    return i;
}


//Recursive Solution: 

int method3(long long n){
    if(n<=0){
        return 0;
    }
    int total=0;
    int curr=method3(n/10);
    total=curr+1;
    return total;
}


//Log based Solution: 
//  We can use log10(logarithm of base 10) to count the number of digits of
//      positive numbers (logarithm is not defined for negative numbers).

int method4(long long n){
    return floor(log10(n)+1);
}

int main(){
    long long n;
    cout<<"Enter the interger"<<endl;
    cin>>n;
    cout<<method1(n)<<endl;
    cout<<method2(n)<<endl;
    cout<<method3(n)<<endl;
    cout<<method4(n)<<endl;
}