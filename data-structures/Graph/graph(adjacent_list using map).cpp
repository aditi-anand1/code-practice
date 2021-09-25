#include<bits/stdc++.h>
using namespace std;
unordered_map<string,list<pair<string,int>>>graph;
void addEdge(string x, string y, bool bidir,int weight){
    graph[x].push_back(make_pair(y,weight));
    if(bidir){
        graph[y].push_back(make_pair(x,weight));    
    }
}

void print(){
    unordered_map<string,list<pair<string,int>>>::iterator itr;
    list<pair<string,int>>::iterator i;
    for(itr=graph.begin();itr!=graph.end();itr++){
        cout<<"head "<<itr->first;
        list<pair<string,int>> ls=itr->second;
        for(i=ls.begin();i!=ls.end();i++){
            cout<<"->{edge: "<<i->first<<", weight: "<<i->second;
        }
        cout<<endl;
    }
}
int main(){
    addEdge("A","B",true,10);
    addEdge("B","D",true,30);
    addEdge("A","C",true,10);
    addEdge("C","D",true,40);
    addEdge("A","D",false,50);
    print();
    
    
()