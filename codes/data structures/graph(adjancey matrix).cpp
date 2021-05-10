#include<iostream>
#include<vector>
using namespace std;
struct edge{
    int start_vertex;
    int end_vertex;
};

// this convert the vertex to the index
int covert_to_index(string a , vector<string>vertex_list ,int n){
    int i;
    for(i=0;i<n;i++){
        if(vertex_list[i]==a){
            break;
        }
    }
    return i;
}

int main(){
    cout<<"This is the implementation of the graph using adjacent matrix"<<endl;
    cout<<"Enter the number of vertex in your grap"<<endl;
    int n;
    cin>>n;
    int edge_vertex[n][n]={0};

    vector<string>vertex_list;
    vector<edge>edge_list;
    for(int i=0;i<n;i++){
        string a;
        cout<<"enter the vertex"<<endl;
        cin>>a;
        vertex_list.push_back(a);
    }
    cout<<"enter the number of edges"<<endl;
    int size_edge;
    cin>>size_edge;
    string s1,s2;
    int sv,ev;
    edge e;
    for(int i=0;i<size_edge;i++){
        cout<<"enter the start vertex & the end vertex"<<endl;
        cin>>s1>>s2;
        sv=covert_to_index(s1,vertex_list,n);
        ev=covert_to_index(s2,vertex_list,n);
        
       e = {sv,ev};
       edge_list.insert(edge_list.end(), e);
       //cin>>edge_list[i].start_vertex;
       // cin>>edge_list[i].end_vertex;
    }
    for(int i=0;i<size_edge;i++){
        edge_vertex[edge_list[i].start_vertex][edge_list[i].end_vertex]=1;
        edge_vertex[edge_list[i].end_vertex][edge_list[i].start_vertex]=1;
    }
    
    cout<<"to find the adjacent vertex"<<endl;
    cout<<"Enter whoes ajacent vertex you want"<<endl;
    string find;

    cin>>find;
    int i=covert_to_index(find,vertex_list,n);
    
    cout<<"adjacent vertexes of "<<find<<"are"<<endl;
    for(int j=0;j<n;j++){
        if(edge_vertex[i][j]==1){
            cout<<vertex_list[j]<<" ";
        }
    }
    cout<<endl;
    cout<<"Now to ckeck whether the to vertex are connected or not"<<endl;
    cout<<"Enter the 2 vertexs you want to check that they are conected or not"<<endl;
    string check1,check2;
    cin>>check1>>check2;
    int indx1=covert_to_index(check1,vertex_list,n);
    int indx2=covert_to_index(check2,vertex_list,n);
    if(edge_vertex[indx1][indx2]==1){
        cout<<"Yes they are connected"<<endl;
    }
    else{
        cout<<"NO they are not connected"<<endl;
    }
    
    cout<<"Enter 1 if you want to add an edge and enter 2 if you want to delete an vertex enter 3 if you dont want to do any of this"<<endl;
    int t;
    cin>>t;
    if(t==1||t==2){
    cout<<"enter the name of the vertex you want to join or delete"<<endl;
    cin>>s1>>s2;
    indx1=covert_to_index(s1,vertex_list ,n);
    indx2=covert_to_index(s2,vertex_list,n);
    if(t==1){
    edge_vertex[indx1][indx2]=1;
    cout<<"your vertexes are succesfully connected"<<endl;
    }
    else{
        edge_vertex[indx1][indx2]=0;
        cout<<"ypur edge is succesfully deleted"<<endl;
    }
    }
    
}
