#include<iostream>
using namespace std;

void rev_print(int n){
    if(n<1){
        return ;
    }
    else{
        cout<<n<<" ";
        return rev_print(n-1);
    }
}
void print(int i,int n){
   
    if(i>n){
        return;
    }
    else{
        cout<<i<<" ";
        i++;
        return print(i,n);
    }
}
int main(){
    int n,i=1;
    cout<<"printing n natural numbers"<<endl;
    cin>>n;
    print(i,n);
    cout<<endl;
    cout<<"now print in reverse order"<<endl;
    rev_print(n);
}