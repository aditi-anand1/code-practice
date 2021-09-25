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
bool isValid(int i,int j,int row,int col){
    if(i>=0 && j>=0 && i<row && j<col){
        return true;
    }
    return false;
}

bool isSafeGlass1(int i, int j, vector<vector<char>>maze, vector<vector<char>>visited){
    if(maze[i][j]=='#' || visited[i][j]=='1'){
        return false;
    }
    return true;
}
bool isSafeGlass2(int i, int j, vector<vector<char>>maze, vector<vector<char>>visited){
    if(maze[i][j]=='*' || visited[i][j]=='1'){
        return false;
    }
    return true;
}
void findShortestDistance(vector<vector<char>>maze, vector<vector<char>>visited, int row, int col, int i, int j, int &min_dist, int dist){
    if(i==row-1 && j==col-1){
        min_dist=min(dist,min_dist);
        return;
    }
   // cout<<dist<<" ";
    visited[i][j]='1';
    if(isValid(i+1,j,row,col) && isSafeGlass1(i+1,j,maze,visited)){
        findShortestDistance(maze,visited,row,col,i+1,j,min_dist,dist+1);
    }
    if(isValid(i,j+1,row,col) && isSafeGlass1(i,j+1,maze,visited)){
        findShortestDistance(maze,visited,row,col,i,j+1,min_dist,dist+1);
    }
    if(isValid(i-1,j,row,col) && isSafeGlass1(i-1,j,maze,visited)){
        findShortestDistance(maze,visited,row,col,i-1,j,min_dist,dist+1);
    }
    if(isValid(i,j-1,row,col) && isSafeGlass1(i,j-1,maze,visited)){
        findShortestDistance(maze,visited,row,col,i,j-1,min_dist,dist+1);
    }
    visited[i][j]='0';
    
}
void findShortestDistance2(vector<vector<char>>maze, vector<vector<char>>visited, int row, int col, int i, int j, int &min_dist2, int dist){
    if(i==row-1 && j==col-1){
        min_dist2=min(dist,min_dist2);
        return;
    }
   // cout<<dist<<" ";
    visited[i][j]='1';
    if(isValid(i+1,j,row,col) && isSafeGlass2(i+1,j,maze,visited)){
        findShortestDistance2(maze,visited,row,col,i+1,j,min_dist2,dist+1);
    }
    if(isValid(i,j+1,row,col) && isSafeGlass2(i,j+1,maze,visited)){
        findShortestDistance2(maze,visited,row,col,i,j+1,min_dist2,dist+1);
    }
    if(isValid(i-1,j,row,col) && isSafeGlass2(i-1,j,maze,visited)){
        findShortestDistance2(maze,visited,row,col,i-1,j,min_dist2,dist+1);
    }
    if(isValid(i,j-1,row,col) && isSafeGlass2(i,j-1,maze,visited)){
        findShortestDistance2(maze,visited,row,col,i,j-1,min_dist2,dist+1);
    }
    visited[i][j]='0';
    
}
int main(){
    int row, col;
    cout<<"row: and col:"<<endl;
    cin>>row>>col;
    vector<vector<char>>maze;

    for(int i=0;i<row;i++){
        cout<<"enter string"<<endl;
        string s;
        cin>>s;
        vector<char>v;
        for(int j=0;j<col;j++){
            v.push_back(s[j]);
        }
        maze.push_back(v);
    }
     vector<vector<char>>visited(row,vector<char>(col,'0'));
    cout<<"The given maze is:"<<endl;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
   
    int min_dist=INT_MAX;
    int min_dist2=INT_MAX;
    findShortestDistance(maze,visited,row,col,0,0,min_dist,0);
    findShortestDistance2(maze,visited,row,col,0,0,min_dist2,0);
    cout<<min_dist<<" "<<min_dist2<<endl;
    min_dist=min(min_dist,min_dist2);
   if (min_dist != INT_MAX)
    {
        cout << "The shortest path from source to destination "
                "has length " << min_dist;
    }
    else {
        cout << "Destination can't be reached from a given source";
    }
}