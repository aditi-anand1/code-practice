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


node* invertTreeRecursion(node* root) {
        if(root==NULL){
            return root;
        }
        invertTreeRecursion(root->left);
        invertTreeRecursion(root->right);
        node* temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        return root;
    }



   
void print(node* root){
    if(root==NULL){
        return ;
    }
    queue<node*>q;
    node* temp;
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
    cout<<"This program is to give the Mirror image of a Binary Search Tree using recursion"<<endl;
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
    cout<<"Tree:"<<endl;
    print(root);
    cout<<"Tree mirror image :"<<endl;
    node* new_root=invertTreeRecursion(root);
    print(new_root);
    cout<<endl;
    
    
    
}