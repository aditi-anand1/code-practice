/**
 *
 * Question : Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.
 *
 *
 *Algorithm : 1) Get the Middle of the array and make it root.
              2) Recursively do same for left half and right half.
                 a) Get the middle of left half and make it left child of the root
                    created in step 1.
                b) Get the middle of right half and make it right child of the
                    root created in step 1.
*/


#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* right;
    node* left;
    
};

node* create(int val){
    node* temp=new node();
    temp->left=NULL;
    temp->right=NULL;
    temp->val=val;
    return temp;
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
int main(){
    int n;
    cout<<"To make the balanced binary seach tree from the given sorted array"<<endl;
    cout<<"Size of array"<<endl;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cout<<"data :"<<endl;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    node* root=NULL;
    root=creatingBalancedTree(v,0,v.size()-1);
    cout<<"Tree in level order traversal form:"<<endl;
    printTree(root);
    
    
}