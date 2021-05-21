/**
 * Question : LCM (Least Common Multiple) of two numbers is the smallest number which can be divided by both numbers.
 * */


#include<iostream>
using namespace std;


//Finding the GCD .
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    if(a==b){
        return a;
    }
    return (a>b)?gcd(a-b,b):gcd(a,b-a);
}


//Finding the minimum value .
int mini(int a,int b){
    return (a>b)?b:a;
}


//Adding the number itself to the minimum among them till both the numbar are not same;
int method1(int a,int b){
    int new_b=b;
    int new_a=a;
   while(new_a!=new_b){
       if(new_a>new_b){
           new_b=new_b+b;
       }
       else{
           new_a=new_a+a;
       }
   }
   return new_a;
}


// By using Formula: a x b = LCM(a, b) * GCD (a, b)
                    //LCM(a, b) = (a x b) / GCD(a, b)
int method2(int a,int b){
    return (a*b)/gcd(a,b);
}


//By finding the prime factors.
int method3(int a,int b){
    int min=mini(a,b);
    int half=min/2;
    int i=2,lcm=1;
    while(i<=half){
        if(a%i==0 && b%i==0){
            a=a/i;
            b=b/i;
            lcm=lcm*i;
        }
        else if(a%i!=0 && b%i==0){
            b=b/i;
            lcm=lcm*i;
        }
        else if(a%i==0 && b%i!=0){
            a=a/i;
            lcm=lcm*i;
        }
        else{
            i++;
        }
    }
    return lcm;
}


int main(){
    int a,b;
    cout<<"Numbers for LCM"<<endl;
    cin>>a>>b;
    cout<<method1(a,b)<<endl;
    cout<<method2(a,b)<<endl;
    cout<<method3(a,b)<<endl;
}