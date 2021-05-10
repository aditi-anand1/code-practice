#include<iostream>
#include<vector>
using namespace std;

//The problem is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down

int gridTravelerBetterDP( int n int m){
    int v[n][m];
    for( int i=0;i<n;i++){
        for( int j=0;j<m;j++){
            if(i==0 || j==0){
                v[i][j]=1;
            }
            else{
                v[i][j]=v[i-1][j]+[i][j-1];
            }
        }
        
    }
    return v[i-1][j-1];
}
int gridTravelerRecursion( int n, int m){
    if(n==1 && m==1){
        return 1;
    }
    if(n==0 || m==0){
        return 0;
    }
    return gridTravelerRecursion(n-1,m) + gridTravelerRecursion(n,m-1);
}

int gridTravelerDP(int n, int m, vector<vector<int>> grid){
     if(n==0 && m==0){
        return 1;
    }
    if(n<0 ||  m<0){
        return 0;
    }
    if(grid[n][m]!=-1){
        return grid[n][m];
    }
    grid[n][m]=gridTravelerDP(n-1,m,grid) + gridTravelerDP(n,m-1,grid);
    return grid[n][m];
}

int main(){
    cout<<"Grid travelling problem is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down"<<endl;
    int row,col;
    cout<<"row:  and   col:"<<endl;
    cin>>row>>col;
    vector<vector<int>>grid(row,vector<int>(col,-1));
    int ways=gridTravelerDP(row-1,col-1,grid);
   cout<<"using memoization "<<ways<<endl;
   cout<<"using recursion "<<gridTravelerRecursion(row,col)<<endl;
   cout<<"using Dp"<<gridTravelerBetterDP(row,col)<<endl;
    
}