/**
 * 
 * Question : Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number. 
 *                  The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n
 * 
 * 
 * Algorithm : 1.We create a list of all numbers from 2 to n. 
 *              2.According to the algorithm we will mark all the numbers which are divisible by 2 and are greater than or equal to the square of it.
 *              3.Now we move to our next unmarked number 3 and mark all the numbers which are multiples of 3 and are greater than or equal to the square of it.
 *              4.We move to our next unmarked number 5 and mark all multiples of 5 and are greater than or equal to the square of it.
 *              5.We continue this process
 * */

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void Sieve_of_Eratosthenes(int n){
    vector<bool>v(n+1,true);
    for (int i=2;i<=n;i++){
         if(v[i]==true){
             for(int j=2;i*j<=n;j++){
                 v[i*j]=false;
             }
         }
    }
  
    for(int i=2;i<=n;i++){
        if(v[i]==true){
            cout<<i<<" ";
        }
    }
}


int main(){
    int n;
    cout<<"Number"<<endl;
    cin>>n;
    Sieve_of_Eratosthenes(n);
}