/**
 * Question: Given a maze we have to find the shorest path to travel from start to end point. yout can move vertically and horizontally.
 * 
 * 
 * */


#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int min(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}

// Returns false if not a valid position
bool isValid(int i,int j,int row,int col){
    if(i>=0 && j>=0 && i<row && j<col){
        return true;
    }
    return false;
}


// Check if it is possible to go to `(x, y)` from the current position. The
// function returns false if the cell has value 0 or already visited
bool isSafe(int i, int j, vector<vector<int>>maze, vector<vector<int>>visited){
    if(maze[i][j]==0 || visited[i][j]){
        return false;
    }
    return true;
}


// Find the shortest possible route in a matrix `mat` from source cell `(0, 0)`
// to destination cell `(x, y)`.
 
// `min_dist` is passed by reference and stores the length of the longest path
// from source to a destination found so far, and `dist` maintains the length
// of the path from a source cell to a current cell `(i, j)`.
void findShortestDistance(vector<vector<int>>maze, vector<vector<int>>visited, int row, int col, int i, int j, int &min_dist, int dist){
    if(i==row-1 && j==col-1){
        // if the destination is found, update `min_dist
        min_dist=min(dist,min_dist);
       
        
        return;
    }
  
   // set `(i, j)` cell as visited
    visited[i][j]=1;
    if(isValid(i+1,j,row,col) && isSafe(i+1,j,maze,visited)){
        findShortestDistance(maze,visited,row,col,i+1,j,min_dist,dist+1);
    }
    if(isValid(i,j+1,row,col) && isSafe(i,j+1,maze,visited)){
        findShortestDistance(maze,visited,row,col,i,j+1,min_dist,dist+1);
    }
    if(isValid(i-1,j,row,col) && isSafe(i-1,j,maze,visited)){
        findShortestDistance(maze,visited,row,col,i-1,j,min_dist,dist+1);
    }
    if(isValid(i,j-1,row,col) && isSafe(i,j-1,maze,visited)){
        findShortestDistance(maze,visited,row,col,i,j-1,min_dist,dist+1);
    }
    // backtrack: remove `(i, j)` from the visited matrix
    visited[i][j]=0;
    
}
int main(){
    int row, col;
    cout<<"row: and col:"<<endl;
    cin>>row>>col;
    vector<vector<int>>maze(row,vector<int>(col));
    for(int i=0;i<row;i++){
        cout<<"enter row"<<endl;
        for(int j=0;j<col;j++){
            cin>>maze[i][j];
        }
    }
     vector<vector<int>>visited(row,vector<int>(col,0));
    cout<<"The given maze is:"<<endl;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
   
    int min_dist=INT_MAX;
    findShortestDistance(maze,visited,4,4,0,0,min_dist,0);
   if (min_dist != INT_MAX)
    {
        cout << "The shortest path from source to destination "
                "has length " << min_dist;
    }
    else {
        cout << "Destination can't be reached from a given source";
    }
}