/**
 * 
 * Question : Given a 2D array where each element contains 1 or 0, where 1 indicates land and 0 indicates water. 
 *              Determine if there is a path by land from a given start point to end point. 
 * 
 * 
 * Algorithm : From every position we have 4 ways to go up,down,right,left that is present_row+1, present_row-1,present_col+1,present_col-1
 *              But we cannot visit the visited node.
 *              So there are 6 base cases where we cannot travel.
 *                  1.when row or col is out of the grid.
 *                      i. row<0 or col<0
 *                      ii.row > row_size or col > col_size 
 *                  2.when we are at water that mean at 0 in grid
 *                  3.when we are the already visitied grid_index
 *                  4.when we are at destination 
 *  
 * */



#include<iostream>
#include<vector>
using namespace std;

// funtion to check whether we can go from source to destination or not
bool check(vector<vector<int>>game, int row_start,int col_start,int row_des,int col_des,int row, int col){
    if(row_start<0 || col_start<0 || row_start>row-1 ||col_start>col-1){
        return 0;
    }
    if(game[row_start][col_start]==0 || game[row_start][col_start]==-1){
        return 0;
    }
    if(row_start==row_des && col_start== col_des){
        return 1;
    }
    game[row_start][col_start]=-1;
    //cout<<row_start<<" "<<col_start<<endl;
    
    return ( check(game,row_start+1,col_start,row_des,col_des,row,col)
            || check(game,row_start,col_start+1,row_des,col_des,row,col)
            || check(game,row_start-1,col_start,row_des,col_des,row,col)
            || check(game,row_start,col_start-1,row_des,col_des,row,col));
    
}

int main(){
    int row,col;
    cout<<"row and col"<<endl;
    cin>>row>>col;
    vector<vector<int>>game(row,vector<int>(col,0));
    cout<<"enter the board game"<<endl;
    // creating the path
    for( int i=0;i<row;i++){
        cout<<"enter row "<<i<<endl;
        for(int j=0;j<col;j++){
            int x;
            cin>>x;
            game[i][j]=x;
        }
    }
cout<<"your grid : "<<endl;
      for( int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<game[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"starting position"<<endl;
    int row_start, col_start;   //source point where you are at
    cin>>row_start>>col_start;
    cout<<"destination position"<<endl;
    int row_des, col_des;
    cin>>row_des>>col_des;  // destination positin where you want to go
    if(game[row_start][col_start]==0){ // if our starting is from water then 
        game[row_start][col_start]=1;
    }
    if(check(game,row_start,col_start,row_des,col_des,row,col)){
        cout<<"true";
    }
    else{
        cout<<"false"; 
    }
}