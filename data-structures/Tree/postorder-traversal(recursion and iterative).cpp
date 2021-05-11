#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
// Creating the new node for the tree
node* createNode(int val){
    node*temp=new node();
    temp->data=val;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}


//Inserting the node according to the binary search tree uding recursion
node* insertioNode(node* root, int val){
    node* temp=createNode(val);
    if(root==NULL){
        return temp;
    }
    if(root->data>temp->data){
        root->left=insertioNode(root->left,val);
    }
    else{
        root->right=insertioNode(root->right,val);
    }
    return root;
}

// printing the tree using postorder by recursion
void postorderTraversalRecusrion(node* root){
    if(root==NULL){
        return;
    }
    postorderTraversalRecusrion(root->left);
    postorderTraversalRecusrion(root->right);
    cout<<root->data<<" ";
    
}

//printing the tree usingpostorder using stack
void postorderTraversalIterative(node* root){
    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);
    node* temp;
   while(!s1.empty()){
       temp=s1.top();
       s1.pop();
       s2.push(temp);
       
       if(temp->left){
           s1.push(temp->left);
       }
       if(temp->right){
           s1.push(temp->right);
       }
   }
   
   while(!s2.empty()){
       temp=s2.top();
       cout<<temp->data<<" ";
       s2.pop();
   }
    return ;
}
int main(){
    cout<<"This program is to print the tree in postorder traversal using recusrion and iterative"<<endl;
    int n;
    cout<<"size of tree:"<<endl;
    cin>>n;
    node* root=NULL;
    while(n--){
        int x;
        cout<<"Node data:"<<endl;
        cin>>x;
        root=insertioNode(root, x);
    }
    cout<<"Tree postorder traversal using recusrion"<<endl;
    postorderTraversalRecusrion(root);
    cout<<endl;
    cout<<"Tree postorder traversal using iterative"<<endl;
    postorderTraversalIterative(root);
    
    
}