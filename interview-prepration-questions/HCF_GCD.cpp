/**
 * Question : GCD (Greatest Common Divisor) or HCF (Highest Common Factor) of two numbers is the largest
 *               number that divides both of them.
 * */


#include<iostream>
using namespace std;

// To find the minimum of the 2 numbers
int mini(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

// Iterative method by finding the minimum's numbre half  and itearting till the half and multiplying the common factors
int method1(int a, int b){
    int min=mini(a,b);
    int half=min/2;
    int i=2,gcd=1;
    while(i<=half){
        if(a%i==0 && b%i==0){
            gcd=gcd*i;
        }
        if(a%i==0){
            a=a/i;
        }
        if(b%i==0){
            b=b/i;
        }
        if(a%i!=0 && b%i!=0){
            i++;
        }
    }
    return gcd;
}


//Iterative method: By finding the minimum numbers half and decrementing the half till half is divided by both the numbers.
int method2(int a,int b){
     int min=mini(a,b);
    int half=min/2;
    while(half>=1){
        if(a%half==0 && b%half==0){
            return half;
        }
        half--;
    }
    return 1;
}

//Recursive Method: If we subtract a smaller number from a larger (we reduce a larger number), GCD doesn’t change.
    // So if we keep subtracting repeatedly the larger of two, we end up with GCD.
int method3(int a,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    if(a==b){
        return a;
    }
    return (a>b)?method3(a-b,b):method3(a,b-a);
}

//Euclid's algorithm: Now instead of subtraction, if we divide the smaller number, the algorithm stops when we find remainder 0.
int method4(int a,int b){
    if (a == 0)
        return b;
    return method4(b % a, a);

}

//Recursive method of the method 4.
int method5(int a, int b, int half){
    if(a%half==0 && b%half==0){
        return half;
    }
    return method5(a,b,half-1);
}

int main(){
    int a,b;
    cout<<"Numbers for the HCF"<<endl;
    cin>>a>>b;
    int min=mini(a,b);
    cout<<"HCF"<<endl;
    cout<<method1(a,b)<<endl;
    cout<<method2(a,b)<<endl;
    cout<<method3(a,b)<<endl;
    cout<<method4(a,b)<<endl;
    cout<<method5(a,b,min/2)<<endl;
}