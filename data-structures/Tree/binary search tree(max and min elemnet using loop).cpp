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
void min(node* root){
    node* ptr=root;
    while(ptr->left!=NULL){
        ptr=ptr->left;
    }
    cout<<ptr->data;
    
}
void max(node* root){
    node* ptr=root;
    while(ptr->right!=NULL){
        ptr=ptr->right;
    }
    cout<<ptr->data;
    
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
        min(root);
        cout<<endl;
    cout<<"the max of the tree is "<<endl;
    max(root);
 
}

