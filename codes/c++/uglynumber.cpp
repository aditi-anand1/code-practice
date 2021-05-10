// ugly number are the numbers whoes factor are only 2,3,5
// this code to to find the nth ugly number using simple looping


#include<iostream>
using namespace std;
int divide(int a,int b){
    while(a%b==0){
        a=a/b;
    }
    return a;
}

int isugly(int no){
    no=divide(no,2);
    no=divide(no,3);
    no=divide(no,5);
    if(no==1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int n,count=1,i=1;
    cout<<"enter the number you want to knw the nth ugly"<<endl;
    cin>>n;
    while(n>count){
        i++;
        if(isugly(i)){
            count++;
        }
    }
    cout<<i;
    
}