/**
   Question:  Given a BST (Binary Search Tree) that may be unbalanced, 
                convert it into a balanced BST that has minimum possible height.

    Algorithm:  1.Traverse given BST in inorder and store result in an array. This step takes O(n) time.
                    Note that this array would be sorted as inorder traversal of BST always produces sorted sequence.
                2.Build a balanced BST from the above created sorted array using the recursive approach discussed here. 
                    This step also takes O(n) time as we traverse every element exactly once and processing an element takes O(1) time.
**/



#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* right;
    node* left;
    
};
vector<int>v;
node* create(int val){
    node* temp=new node();
    temp->left=NULL;
    temp->right=NULL;
    temp->val=val;
    return temp;
}
node* creatingBST(node* root, int val){
    node* temp=create(val);
    if(root==NULL){
        root=temp;
        return root;
    }
    else if(root->val>val){
        root->left=creatingBST(root->left,val);
    }
    else{
        root->right=creatingBST(root->right,val);
    }
    return root;
}

node* creatingBalancedTree(vector<int>v, int start, int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    node* root= create(v[mid]);
    root->left=creatingBalancedTree(v,start,mid-1);
    root->right=creatingBalancedTree(v,mid+1,end);
    return root;
}

void printTree(node* root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    node* temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

void inorder_to_make_vector(node* root){
    if(root==NULL){
        return ;
    }
    inorder_to_make_vector(root->left);
    v.push_back(root->val);
    inorder_to_make_vector(root->right);
}
int main(){
    int n;
    cout<<"To balace a binary search tree"<<endl;
    cout<<"Size of Tree"<<endl;
    cin>>n;
    
    node* root=NULL;
    for(int i=0;i<n;i++){
        int x;
        cout<<"data :"<<endl;
        cin>>x;
        root=creatingBST(root,x);
        
    }
    inorder_to_make_vector(root);
    cout<<"Printing of tree is on level order traversal"<<endl;
    cout<<"Binary search tree: "<<endl;
    printTree(root);
    cout<<endl;
    root=creatingBalancedTree(v,0,v.size()-1);
    cout<<"Balanced Binary search Tree"<<endl;
    printTree(root);
    
    
}