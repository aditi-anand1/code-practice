#include<iostream>
using namespace std;

int fib(int n){
    int arr[n+1]={0};
    arr[1]=1;
    for( int i=0;i<n;i++){
        arr[i+1]+=arr[i];
        arr[i+2]+=arr[i];
    }
    return arr[n];
}
int main(){
    int n;
    cout<<"Enter the number whoes fibonacci you want "<<endl;
    cin>>n;
    cout<<"Fibonacci of "<<n<<" is : "<<fib(n);
    
}