
#include <iostream>

using namespace std;
int max(int a,int b);

int longest_common_sequence(string s1,string s2){
     int l1=s1.size();
     int l2=s2.size();
    int arr[l1+1][l2+1];   //creating 2D array to store the values
    int i,j;

    /* Following steps build L[m+1][n+1] in  
       bottom up fashion. Note that L[i][j]  
       contains length of LCS of X[0..i-1] 
       and Y[0..j-1] */

    for( i=0;i<=l1;i++){
        for( j=0;j<=l2;j++){
            if(i==0||j==0){     
                arr[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else{
                arr[i][j]=max(arr[i-1][j],arr[ i][j-1]);     
            }
        }
    }
    
    return arr[l1][l2];
}


/* Utility function to get max of 2 integers */
int max(int a,int b){
    return (a>b)?a:b;
}
int main()
{   cout<<"This code is to find the longest common sequence"<<endl;
    string s1,s2;
    cout<<"enter the first string "<<endl;
    cin>>s1;
    cout<<"enter the second string"<<endl;
    cin>>s2;
    
    int answer=longest_common_sequence(s1,s2);
    cout<<answer<<endl;
    

    return 0;
}
