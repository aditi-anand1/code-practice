/**
 * Question : Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 
 * 
 * */


#include<iostream>
#include<vector>
using namespace std;
int longestCommonSubstring(string main_string, string sub_string, int n , int m, int count){
  if(n==0||m==0){
      return count;
  }
  else if(main_string[n-1]==sub_string[m-1]){
      count=longestCommonSubstring(main_string,sub_string,n-1,m-1,count+1);
  }
   count = max(count,
                max(longestCommonSubstring(main_string,sub_string,n, m - 1, 0),
                    longestCommonSubstring(main_string,sub_string,n - 1, m, 0)));
    return count;
}


int main(){
    string main_string,sub_string;
    cout<<"Enter the string"<<endl;
    cin>>main_string;
    cout<<"String whoes longest common substring you want"<<endl;
    cin>>sub_string;
    int n=main_string.size();
    int m=sub_string.size();
    cout<<"Lenght of longest common substring is "<<longestCommonSubstring(main_string,sub_string,n,m,0);

}