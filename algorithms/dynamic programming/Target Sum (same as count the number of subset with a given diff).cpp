/**
 * Question : You are given an integer array nums and an integer target.You want to build an expression out of nums
 *               by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
                For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
                Return the number of different expressions that you can build, which evaluates to target.
 * Samples Case : Input: nums = [1,1,1,1,1], target = 3
                  Output: 5

                  -1 + 1 + 1 + 1 + 1 = 3
                  +1 - 1 + 1 + 1 + 1 = 3
                  +1 + 1 - 1 + 1 + 1 = 3
                  +1 + 1 + 1 - 1 + 1 = 3
                  +1 + 1 + 1 + 1 - 1 = 3

 * This is same as the count the number subset with agiven differnce in this also we are basically adding all the negative numbers
    subset to the positive one so its s1-s2=target exact same ques 
 * */ 


#include<iostream>
#include<vector>
using namespace std;


//to fine the sum of the array
int sumOfArray(vector<int>arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum=sum+arr[i];
    }
    return sum;
}

//To count the number of subset present with teh given sum in the array
int countOfSubsetSum(int sum , vector<int>arr){
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<arr[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}


// to give the number of subset with teh given diff
int targetSum(int diff, vector<int>arr){
            vector<int>arr;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(arr[i]!=0){
                nums.push_back(arr[i]); //making an array without zero and counting number of zeros
            }
            else{
                zero++;
            }
        }
    int sum_arr=sumOfArray(nums);
    if((sum_arr+target)%2!=0)return 0;
    int sum=(diff+sum_arr)/2;
    int count=countOfSubsetSum(sum,nums);
    count = ( count * pow(2, zero)); // to adjust the number zero 
    return count;
    
}

int main(){
    int size;
    cout<<"Size of array"<<endl;
    cin>>size;
    vector<int>arr;
    for(int i=0;i<size;i++){
        int x;
        cout<<"Data "<<i<<endl;
        cin>>x;
        arr.push_back(x);
    }
    int target;
    cout<<"Difference :"<<endl;
    cin>>target;
    cout<<"Number of subset present whoes sum is "<<target<<" is ";
    cout<<targetSum(diff, arr);
}