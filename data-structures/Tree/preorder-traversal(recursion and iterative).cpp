#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* createNode(int val){
    node*temp=new node();
    temp->data=val;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

node* insertioNode(node* root, int val){
    node* temp=createNode(val);
    if(root==NULL){
        return temp;
    }
    if(root->data>temp->data){
        root->left=insertioNode(root->left,val);
    }
    else{
        root->right=insertioNode(root->right,val);
    }
    return root;
}

void preorderTraversalRecusrion(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversalRecusrion(root->left);
    preorderTraversalRecusrion(root->right);
    
}

void preorderTraversalIterative(node* root){
    stack<node*>s;
    node* temp=root;
    while(temp!=NULL || !s.empty()){
        if(temp!=NULL){
            cout<<temp->data<<" ";
            s.push(temp);
            temp=temp->left;
        }
        else{
            temp=s.top();
            s.pop();
            temp=temp->right;
        }
    }
    return ;
}
int main(){
    cout<<"This program is to print the tree in preorder traversal using recusrion and iterative"<<endl;
    int n;
    cout<<"size of tree:"<<endl;
    cin>>n;
    node* root=NULL;
    while(n--){
        int x;
        cout<<"Node data:"<<endl;
        cin>>x;
        root=insertioNode(root, x);
    }
    cout<<"Tree preorder traversal using recusrion"<<endl;
    preorderTraversalRecusrion(root);
    cout<<endl;
    cout<<"Tree preorder traversal using iterative"<<endl;
    preorderTraversalIterative(root);
    
    
}