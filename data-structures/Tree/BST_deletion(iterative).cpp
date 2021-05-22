#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* create(int val){
    node* temp=new node();
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node* insertion(int val, node* root){
    node* temp=create(val);
    if(root==NULL){
        root=temp;
        return root;
    }
     else if(val<=root->data){
        root->left=insertion(val,root->left);
    }
    else{
        root->right=insertion(val,root->right);
    }
    
    return root;
}

node* minNode(node* root){
    node* temp=root;
    
    while(temp!=NULL && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* deletion(int val,node* root){
    if (root == NULL)
        return root;
    node* parent =NULL;
    node* child=root;
    while(child->data!=val){
        parent=child;
        if(child->data>val){
            child=child->left;
        }
        else{
            child=child->right;
        }
    }
    
    if(child->left==NULL && child->right==NULL){
        if(parent==NULL){
            return NULL;
        }
        if(parent->left==child){
            parent->left=NULL;
        }
        else{
            parent->right=NULL;
        }
    }
    else if(child->left!=NULL && child->right==NULL){
        if(parent==NULL){
            root =child->left;
            return root;
        }
          if(parent->left==child){
            parent->left=child->left;
        }
        else{
            parent->right=child->left;
        }
    }
      else if(child->left==NULL && child->right!=NULL){
          if(parent==NULL){
            root =child->right;
            return root;
        }
          if(parent->left==child){
            parent->left=child->right;
        }
        else{
            parent->right=child->right;
        }
    }
    else{
        node* left_most=child->right;
        node* left_most_parent=NULL;
        while(left_most->left!=NULL){
            left_most_parent=left_most;
            left_most=left_most->left;
        }
        if(left_most_parent!=NULL){
            left_most_parent->left=left_most->right;
        }
        else{
            child->right=left_most->right;
        }
        child->data=left_most->data;
       
    }
   return root;
}


void print(node* root){
    if(root==NULL){
        return ;
    }
    queue<node*>q;
    node* temp=root;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
int main(){
    int n;
    cout<<"size of tree:"<<endl;
    cin>>n;
    node* root=NULL;
    while(n--){
        int x;
        cout<<"tree data:"<<endl;
        cin>>x;
        root=insertion(x,root);
    }
    
    cout<<"Tree formed"<<endl;
    print(root);
    cout<<endl;
    int del;
    cout<<"enter the node you want to delete"<<endl;
    cin>>del;
    cout<<"Tree after deletion is:"<<endl;
    root=deletion(del,root);
    print(root);
    
}