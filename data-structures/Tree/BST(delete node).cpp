#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* create(int data){
    node* root=new node;
    root->right=NULL;
    root->left=NULL;
    root->data=data;
    return root;
}

node* insert(node* root,int data){
    if(root==NULL){
        root=create(data);
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
}

void print(node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
node* minmum_value(node* root){
    if(root->left==NULL){
        return root;
    }
    else{
    minmum_value(root->left);
    }
}

node* deleting(node* root,int data){
    if(root==NULL){
        return root;
    }
   else if(data<root->data){
       root->left=deleting(root->left,data);
   }
   else if(data>root->data){
       root->right=deleting(root->right,data);
   }
   else{
       // when u found the node which u want to delete
       if(root->left==NULL&&root->right==NULL){
           root=NULL;
           return root;
       }
       else if(root->left==NULL){
           node* temp=root;
           root=root->right;
           delete temp;
       }
       else if(root->right==NULL){
           node* temp=root;
           root=root->left;
           delete temp;
       }
       else{
           node* min=minmum_value(root->right);
           root->data=min->data;
           root->right=deleting(root->right,min->data);
           
       }
   }
   return root;
    
}
int main(){
    int n,data;
    cout<<"enter the number of node u want in ur tree"<<endl;
    cin>>n;
    node* root=NULL;
    while(n--){
        cout<<"enter the data"<<endl;
        cin>>data;
        root=insert(root,data);
    }
    cout<<"so your tree is"<<endl;
    print(root);
    cout<<endl;
    cout<<"enter the value u want to delete from the tree"<<endl;
    int del;
    cin>>del;
    root=deleting(root,del);
    cout<<"so now your new tree is after deletion is"<<endl;
    print(root);
    
    
    
}