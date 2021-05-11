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


node* invertTreeIterative(node* root) {
     if(root==NULL){
            return root;
    }
    stack<node*>s;
    s.push(root);
    node* temp=root;
    while(!s.empty()){
        temp=s.top();
        s.pop();
            
        if(temp->left && temp->right){
            node* exchange=temp->left;
            temp->left=temp->right;
            temp->right=exchange;
            s.push(temp->left);
            s.push(temp->right);
        }
        else if(!temp->left && temp->right){
            s.push(temp->right);
            temp->left=temp->right;
            temp->right=NULL;
        }
        else if(temp->left && !temp->right){
             s.push(temp->left);
             temp->right=temp->left;
            temp->left=NULL;
        }
    }
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
    cout<<"This program is to give the Mirror image of a Binary Search Tree using iterative"<<endl;
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
    cout<<"Tree mirror image using iterative"<<endl;
    node* new_root=invertTreeIterative(root);
    print(new_root);
    cout<<endl;
    
    
    
}