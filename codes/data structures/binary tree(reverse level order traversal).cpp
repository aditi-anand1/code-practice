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
    node* right;
    node* left;
};
void reversal_order_traversal(node* root,int x);
int height(node* root);
void changing_level(node* root);

node* create(int data){
    node* temp=new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node* insert(node* root,int i,int n,vector<int>v){
   if(i<n){
       node* temp=create(v[i]);
       root=temp;
       root->left=insert(root->left,2*i+1,n,v);
       root->right=insert(root->right,2*i+2,n,v);
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

int height(node* root){
    if(root==NULL){
        return 0;
    }
   int lheight= height(root->left);
   int rheight=height(root->right);
   if(lheight>rheight){
       return lheight+1;
   }
   else{
       return rheight+1;
   }
}
void changing_level(node* root){
    int h =height(root);
    int i;
    for(i=h;i>=1;i--){
        reversal_order_traversal(root,i);
    }
}
void reversal_order_traversal(node* root,int x){
    if(root==NULL){
        return;
    }
    if(x==1){
        cout<<root->data<<" ";
    }
    else if(x>1){
        reversal_order_traversal(root->left,x-1);
        reversal_order_traversal(root->right,x-1);
        
    }
}
int main()
{
    int n;
    cout<<"enter the element you want in yourr tree"<<endl;
    cin>>n;
    vector<int>v;
    node* root=NULL;
    for(int i=0;i<n;i++){
        int num;
        cout<<" enter the element "<<endl;
        cin>>num;
        v.push_back(num);
    }
    root=insert(root,0,n,v);
    cout<<" ******tree is*****"<<endl;
    print(root);
    cout<<endl;
    cout<<"height of the tree"<<endl;
    int x=height(root);
    cout<<x;
    cout<<"printing the tree into reverse order traversal"<<endl;
     changing_level(root);
        
        
    

    return 0;
}
