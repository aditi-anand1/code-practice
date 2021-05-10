#include<iostream>
#include<queue>
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

void level_travesal(node* root){
    if(root==NULL){
        cout<<"empty tree"<<endl;
        return;
    }
    else{
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}
}
int main(){
    int n,num;
    node* root=NULL;
    cout<<"enter the number of nodes you want in your tree"<<endl;
    cin>>n;
    while(n--){
        cout<<"enter the number"<<endl;
        cin>>num;
        root=insert(root,num);
    }
    cout<<"your tree is"<<endl;
    level_travesal(root);
}