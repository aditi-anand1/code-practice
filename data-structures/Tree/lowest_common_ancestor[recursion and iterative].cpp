/**
 *  Question : To find the lowest common ancestor of Binary Search Tree
 *              Lowest Common Ancestor: The lowest common ancestor is defined between two nodes 
 *                  node1 and node2 as the lowest node in T that has both node1 and node2 as descendants
 *                   (where we allow a node to be a descendant of itself).
 * 
 * Algorithm : 1.Create a recursive function that takes a node and the two values n1 and n2.
               2.If the value of the current node is less than both n1 and n2, then LCA lies in the right subtree. Call the recursive function for thr right subtree.
               3.If the value of the current node is greater than both n1 and n2, then LCA lies in the left subtree. Call the recursive function for thr left subtree.
               4.If both the above cases are false then return the current node as LCA.
 * */

#include<iostream>
#include<queue>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
};

node* create(int val){
    node* temp=new node();
    temp->right=NULL;
    temp->left=NULL;
    temp->val=val;
    return temp;
}

node* insert(node* root, int val){
    node* temp=create(val);
    
    if(root==NULL){
        root=temp;
        return root;
    }
    else if(root->val>val){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}


node* lowestCommonAncestorRecursion( int n1, int n2, node* root){
    if(root==NULL){
        return root;
    }
    
    if(root->val>n1 && root->val>n2){
        return lowestCommonAncestorRecursion(n1,n2,root->left);
    }
    if(root->val<n1 && root->val<n2){
        return lowestCommonAncestorRecursion(n1,n2,root->right);
    }
    return root;
}

node* lowestCommonAncestorIterative(int n1, int n2, node* root){
    node* temp=root;
    while(temp!=NULL){
        if(temp->val>n1 && temp->val>n2){
            temp=temp->left;
        }
        else if(temp->val<n1 && temp->val<n2){
            temp=temp->right;
        }
        else{
            return temp;
        }
    }
    return temp;
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
    cout<<"size of tree:"<<endl;
    cin>>n;
    node* root=NULL;
    while(n--){
        int x;
        cout<<"Data:"<<endl;
        cin>>x;
        root=insert(root,x);
    }
    cout<<"Tree"<<endl;
    print(root);
    cout<<endl;
    cout<<"Enter the two values whoes lowest common ancestor you want to find"<<endl;
    int n1,n2;
    cin>>n1>>n2;
    node* lca=lowestCommonAncestorRecursion(n1,n2,root);
    cout<<"Lowest common ancestor of "<<n1<<" and "<<n2<<" using recursion is: "<<lca->val<<endl;
    lca=lowestCommonAncestorIterative(n1,n2,root);
    cout<<"Lowest common ancestor of "<<n1<<" and "<<n2<<" using iterative is: "<<lca->val<<endl;
    
}