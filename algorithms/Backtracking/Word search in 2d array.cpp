#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>>board;


bool backtrack(int row, int col, string word, int index){
    if(index>=word.size()){
        return true;
    }
    if(row<0 ||row>=board.size()||col<0||col>=board[0].size()||board[row][col]!=word[index]){
        return false;
    }
    
    board[row][col]='#';
    int rowOff[]={1,0,-1,0};
    int colOff[]={0,1,0,-1};
    bool res=false;
    
    for(int i=0;i<4;i++){
        res=backtrack(row+rowOff[i],col+colOff[i],word,index+1);
        if(res){
            break;
        }
    }
    board[row][col]=word[index];
    return res;
}

bool search(vector<vector<char>>puzzle, string word){
    int n=puzzle.size();
    int m=puzzle[0].size();
    for(int i=0;i<n;i++){
        vector<char>v;
        for(int j=0;j<m;j++){
            v.push_back(puzzle[i][j]);
        }
        board.push_back(v);
    }
    
    int index=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(backtrack(i,j,word,index)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int m,n;
    cout<<"now of rows and col of the puzzel"<<endl;
    cin>>n>>m;
    vector<vector<char>>puzzel(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            puzzel[i][j]=ch;
        }
    }
    string word;
    cout<<"Enter the word you want to search"<<endl;
    cin>>word;
    if(search(puzzel,word)){
        cout<<"Word is there in puzzle"<<endl;
    }
    else{
        cout<<"Word is not there in puzzle"<<endl;
    }
    
    
    
}
