#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>s;
    stack<int>min;
    int n;
    cout<<"Enter the number of element you want to enter"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Tell you want to PUSH or POP the element"<<endl;
        string op;
        cin>>op;
        if(op=="PUSH"){
             int t;
             cout<<"Enter the number"<<endl;
             cin>>t;
             if(s.empty()||(t<min.top())){
                 min.push(t);
                 s.push(t);
             }
             else{
                s.push(t);
                 }
             }
        else{
            if(s.top()==min.top()){
                s.pop();
                min.pop();
            }
            else
            {
                s.pop();
            }
            
        }
             
             
            cout<<"currently the minimun element in the stack is"<<min.top()<<endl;

        }
       
        
    
}
