#include<iostream>
#include<vector>
using namespace std;
struct node{
    int end_vertex;
    int weight;
    node* next;
};

int index_convertor(string a,vector<string>vertex_list){
    int i;
    for(i=0;i<vertex_list.size();i++){
        if(vertex_list[i]==a){
            break;
        }
    }
    return i;
}

node* linkedlist_creation(node* head,int n,int weight){
    node* temp=new node();
    node* ptr=head;
    temp->end_vertex=n;
    temp->next=NULL;
    //cout<<"Enter the weight of the edge"<<endl;
    temp->weight=weight;
    if(head==NULL){
        head=temp;
    }
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    return head;
}

void dispaly(node* head,vector<string>vertex_list){
    node* ptr=head;
    while(ptr!=NULL){
       cout<<vertex_list[ptr->end_vertex]<<" ";
       ptr=ptr->next;
    }
}
int main(){
    cout<<"Enter the number of edges you want in your graph"<<endl;
    int n;
    cin>>n;
    vector<string>vertex_list;
    for(int i=0;i<n;i++){
        string a;
        cout<<"enter the vertex"<<endl;
        cin>>a;
        vertex_list.push_back(a);
    }
    cout<<"enter the number of edges you want in your garph"<<endl;
    int edge_size;
    cin>>edge_size;
    node *edge_list[edge_size];
    node* head=NULL;
    for(int i=0;i<edge_size;i++){
        cout<<"enter the start vertex and the end vertex"<<endl;
        string s1,s2;
        cin>>s1>>s2;
        cout<<"enter the weight"<<endl;
        int w;
        cin>>w;
        int sv,ev;
        sv=index_convertor(s1,vertex_list);
        ev=index_convertor(s2,vertex_list);
        edge_list[sv]=linkedlist_creation(head,ev,w);
        edge_list[ev]=linkedlist_creation(head,sv,w);
    }
    
    cout<<"enter the vertex whoes adjacent vertex you want to check"<<endl;
    string find;
    cin>>find;
    int x=index_convertor(find,vertex_list);

    head=edge_list[x];
   
    dispaly(head,vertex_list);
        
}