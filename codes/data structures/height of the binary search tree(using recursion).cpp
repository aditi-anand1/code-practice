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

node* insert(node* root,int data){
    node* temp=create(data);
    if(root==NULL){
        root=temp;
        return root;
    }
    node* child=root;
    node* parent=NULL;
    while(child!=NULL){
        parent=child;
        if(data<=child->data){
            child=child->left;
        }
        else{
            child=child->right;
        }
    }
    if(data<=parent->data){
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
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int depth(node* root){
    if(root==NULL){
        return 0;
    }
    int ld=depth(root->left);
    int rd=depth(root->right);
    if(ld>rd){
        return ld+1;
    }
    else{
        return rd+1;
    }
}
int main(){
    int n,num;
    node* root=NULL;
    cout<<"enter the number of element you want in your tree"<<endl;
    cin>>n;
    while(n--){
        cout<<"enter the number"<<endl;
        cin>>num;
        root=insert(root,num);
    }
    print(root);
    cout<<endl;
    cout<<"height of the tree is"<<endl;
    cout<<depth(root);
}