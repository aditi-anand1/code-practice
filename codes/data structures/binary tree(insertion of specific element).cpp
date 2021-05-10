#include<iostream>
#include<vector> 
#include<queue> 
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* create(int data){
    node* temp=new node();
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;
    return temp;
}

node* insertion(vector<int>v,node* root,int i,int n){
    if(i<n){
        node* temp=create(v[i]);
        root=temp;
        
        root->left=insertion(v,root->left,2*i+1,n);
        root->right=insertion(v,root->right,2*i+2,n);
    }
    return root;
}

void print(node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

node* specific_insert(node* root,int data){
    queue<node*>q;
    q.push(root);
    
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp->left==NULL){
            temp->left=create(data);
            break;
        }
        else{
            q.push(temp->left);
        }
        if(temp->right==NULL){
            temp->right=create(data);
            break;
        }
        else{
            q.push(temp->right);
        }
    }
    return root;
}


int main(){
    int n,i,num;
    vector<int>v;
    cout<<"enter the number of element you want in ur tree"<<endl;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>num;
        v.push_back(num);
    }
    node* root=NULL;
    root=insertion(v,root,0,n);
    print(root);
    cout<<"emter the number you want to insert in the tree"<<endl;
    cin>>num;
    root=specific_insert(root,num);
    cout<<"after the inserttion the tree is"<<endl;
    print(root);
    
    
}
