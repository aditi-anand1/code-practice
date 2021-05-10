#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* create(int data){
    node* temp=new node();
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
node* insertion(vector<int>v,node* root, int i,int n){
    if(i<n){
        node* temp=create(v[i]);
        root=temp;
        
        root->left=insertion(v,root->left,2*i+1,n);
        
        root->right=insertion(v,root->right,2*i+2,n);
    }
    return root;
}

void print(node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main(){
    vector<int>v;
    cout<<"thsi is the formation of the tree using array in level order traversal"<<endl;
    cout<<"enter the numbre of element you want in your tree"<<endl;
    int n,i;
    cin>>n;
    cout<<"enter the element you want in your tree"<<endl;
    for( i=0;i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    
    node* root=NULL;
    root=insertion(v,root,0,n);
    print(root);
    
    
}