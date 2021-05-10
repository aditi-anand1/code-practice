#include<iostream>
using namespace std;
struct node{
    int data;
    node* right;
    node* left;
};

node* create_node(int data){
    node* temp=new node();
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

node* insert(node* root, int data){
    if(root==NULL){
        root=create_node(data);
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

void print_inorder(node* root){
    if(root==NULL){
        return;
    }
     print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}
void print_preorder(node* root){
     if(root==NULL){
        return;
    }
     
    cout<<root->data<<" ";
   print_preorder(root->left);
    print_preorder(root->right);
}
void print_postorder(node* root){
      if(root==NULL){
        return;
      }
   print_postorder(root->left);
    print_postorder(root->right);
     cout<<root->data<<" ";
}
bool searching(node* root,int search){
    if(root==NULL){
        return false;
    }
    else if(root->data==search){
        return true;
    }
    else if(root->data>search){
        searching(root->left,search);
    }
    else{
        searching(root->right,search);
    }
}
int main(){
    node* root=NULL;
    int n,num;
    cout<<"enter the number you want to enter in the tree"<<endl;
    cin>>n;
    while(n--){
        cout<<"enter thr number"<<endl;
        cin>>num;
        root=insert(root,num);
    }
    cout<<"this is the inorder printing"<<endl;
    print_inorder(root);
    cout<<endl;
    cout<<"this is the preorder printing"<<endl; 
    print_preorder(root);
    cout<<endl;
    cout<<"this is the postorder printing"<<endl;
    print_postorder(root);
    int search;
    cout<<endl;
    cout<<"what number you want to search in the tree"<<endl;
    cin>>search;
    if(searching(root,search)){
        cout<<"the number is present in the tree"<<endl;
    }
    else{
        cout<<"not present in the tree"<<endl;
    }
}