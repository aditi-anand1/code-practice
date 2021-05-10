#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* creat_node(int data){
    node* temp=new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node* insert(node* root,int data){
    if(root==NULL){
        root=creat_node(data);
        return root;
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
int min(node* root){
    if(root==NULL){
        return -1;
    }
    else if(root->left==NULL){
        return root->data;
    }
    else{
        min(root->left);
    }
}

int max(node* root){
      if(root==NULL){
        return -1;
    }
    else if(root->right==NULL){
        return root->data;
    }
    else{
        min(root->right);
    }
}
int main(){
    node* root=NULL;
    int n,num;
    cout<<" enter the number of element you want to enter in your tree"<<endl;
     cin>>n;
     while(n--){
         cout<<"enter the number"<<endl;
         cin>>num;
         root=insert(root,num);
     }
     cout<<"the min of the tree is "<<endl;
        cout<<min(root)<<endl;
        
    cout<<"the max of the tree is "<<endl;
    max(root);
 
}

