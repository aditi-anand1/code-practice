#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};

node* create(int val){
    node* temp=new node();
    temp->data=val;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

int min(int a, int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
int minDepthRecursion( node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    int left=INT_MAX,right=INT_MAX;
    if(root->left){
        left=minDepthRecursion(root->left);
    }
    if(root->right){
        right=minDepthRecursion(root->right);
    }
    return min(left,right)+1;
}


int minDepthIterative(node* root){
    if(root==NULL){
        return 0;
    }
    queue<node*>q;
    q.push(root);
    int depth=0;
    while(!q.empty()){
        int size=q.size();
        depth++;
        while(size>0){
            node* temp=q.front();
            q.pop();
            
            if( temp->left==NULL && temp->right==NULL){
                return depth;
            }
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            size--;
        }
    }
    return depth;
}

node* insertion( int val, node* root){
    node* temp=create(val);
    if( root==NULL){
        return temp;
    }
    node* parent=root;
    node* child=parent;
    while(parent!=NULL){
        child=parent;
        if(temp->data<parent->data){
            parent=parent->left;
        }
        else{
            parent=parent->right;
        }
    }
    if(temp->data<child->data){
        child->left=temp;
    }
    else{
        child->right=temp;
    }
    return root;
}

void print( node* root){
    if(root==NULL){
        return ;
    }
    print(root->left);
    cout<<root->data<<" ";
    print( root->right);
}

int main(){
    cout<<"Minimum depth of the tree using recursion and iterative approach"<<endl;
    int n;
    cout<<"Size of the tree:"<<endl;
    cin>>n;
    node* root=NULL;
    while(n--){
        int x;
        cout<<"Value of node:"<<endl;
        cin>>x;
        root=insertion(x, root);
    }
    cout<<"Tree repress=entation using inorder traversal"<<endl;
    print(root);
    cout<<endl;
    cout<<"Minimum depth of the tree using recusrion : "<<minDepthRecursion(root)<<endl;
    cout<<"Minimum depth of the tree using iterative : "<<minDepthIterative(root)<<endl;
    
}