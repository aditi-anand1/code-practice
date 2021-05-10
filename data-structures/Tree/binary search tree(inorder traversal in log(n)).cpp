#include<iostream>
#include<stack>
using namespace std;
struct node{
    int data;
    node* right;
    node* left;
};
node* create(int val){
    node* temp=new node();
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

//insertion with iterative approach
node* insertion(node* root, int val){
    node* temp=create(val);
    if(root==NULL){
        root=temp;
        return root;
    }
    node* child=root;
    node* parent=NULL;
    while(child!=NULL){
        parent=child;
        if(child->data>=val){
            child=child->left;
        }
        else{
            child=child->right;
        }
    }
    if(parent->data>=val){
        parent->left=temp;
    }
    else{
        parent->right=temp;
    }
    return root;
}
//inorder traversal in log(n) complexity
void print(node* root){
    stack<node*>s;
    node* curr=root;
    while(!s.empty() || curr!=NULL){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            curr=s.top();
            cout<<curr->data<<" ";
            s.pop();
            curr=curr->right;
        }
    }
}

int main(){
    int n;
    cout<<"size:"<<endl;
    cin>>n;
    node* root=NULL;
    while(n--){
        int val;
        cout<<"value:"<<endl;
        cin>>val;
        root=insertion(root, val);
    }
    print(root);
}