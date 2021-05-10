/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
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
    temp->left=NULL;
    node* right=NULL;
    return temp;
}
node* insert(vector<int>v,int n,int i,node* root){
    if(i<n){
        node* temp=create(v[i]);
        root=temp;
        root->left=insert(v,n,2*i+1,root->left);
        root->right=insert(v,n,2*i+2,root->right);
    }
    return root;
}
bool isMirror(node* root1,node* root2){
    if(root1==NULL&&root2==NULL){
        return true;
    }
    if(root1&&root2&&root1->data==root2->data){
        return isMirror(root1->left,root2->right)&&isMirror(root1->right,root2->left);
    }
    return false;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{   vector<int>v;
    int n;
    cout<<"enter the number of nodes you want in your tree"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cout<<"enter the element you want in your tree"<<endl;
        cin>>num;
        v.push_back(num);
    }
    node* root=NULL;
    root=insert(v,n,0,root);
    inorder(root);
    cout<<endl;
    if(isMirror(root,root)){
        cout<<"Yes this is symmetric Tree"<<endl;
    }
    else{
        cout<<"No this is not symmetric Tree"<<endl;
    }
    
    

    return 0;
}
