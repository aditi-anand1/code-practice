/**
 * Question: Given a boolean expression with following symbols. 
        Symbols
            'T' ---> true 
            'F' ---> false 
        And following operators filled between symbols 

        Operators
            &   ---> boolean AND
            |   ---> boolean OR
            ^   ---> boolean XOR 
        Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true. 
 * 
 * Sample: Input : "T | T & F ^ T"
 *          Output: 4
                The given expression is "T | T & F ^ T", it evaluates true
                in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) 
                and (T|((T&F)^T)).
 *
 **/

#include<iostream>
#include<vector>
using namespace std;

int evaluateExpression(string s, int isTrue , int i , int j){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue==1){
            return s[i]=='T';
        }
        else{
            return s[i]=='F';
        }
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2){
        int lt=evaluateExpression(s,1,i,k-1);
        int lf=evaluateExpression(s,0,i,k-1);
        int rt=evaluateExpression(s,1,k+1,j);
        int rf=evaluateExpression(s,0,k+1,j);
        if(s[k]=='&'){
            if(isTrue==1){
                ans=ans+lt*rt;
            }
            else{
                ans=ans+lt*rf+lf*rf+lf*rt;
            }
        }
         if(s[k]=='|'){
            if(isTrue==1){
                ans=ans+lt*rt+lt*rf+lf*rt;
            }
            else{
                ans=ans+lf*rf;
            }
        }
         if(s[k]=='^'){
            if(isTrue==1){
                ans=ans+lf*rt+lt*rf;
            }
            else{
                ans=ans+lt*rt+lf*rf;
            }
        }
    }
    return ans;
}
int main(){
  string s;
  cout<<"string:"<<endl;
  cin>>s;
  cout<<evaluateExpression(s,1,0,s.size()-1);
}
