#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* create(int data){
    node* temp=new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node* insert(node* root, int data){
    node* temp=create(data);
    if(root==NULL){
        root=temp;
        return root;
    }
    node* child=root;
    node* parent=NULL;
    while(child!=NULL){
        parent=child;
        if(child->data>=data){
            child=child->left;
        }
        else{
            child=child->right;
        }
    }
    if(parent->data>=data){
        parent->left=temp;
    }
    else{
        parent->right=temp;
    }
    return root;
}

void print(node* root){
    if(root==NULL){
        return;
    }
   // node* ptr=root;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
int main(){
    node* root=NULL;
    int n,data;
    cout<<"number of nodes you want in your tree"<<endl;
    cin>>n;
    while(n--){
        cout<<"enter the number"<<endl;
        cin>>data;
        root=insert(root,data);
    }
    cout<<"your tree is"<<endl;
    print(root);
}