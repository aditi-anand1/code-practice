#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};

node* create(int n){
    node* head=NULL;
    node* ptr=head;
    while(n--){
        node* temp=new node();
        int dat;
        cin>>dat;
        temp->data=dat;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            ptr=head;
        }
        else{
            ptr->next=temp;
            ptr=ptr->next;
        }
        
    }
    return head;
}

node* reverse(node* head){
    node* current=head;
    node* prev=NULL;
    node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}

void print(node* head){
    node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main(){
    int n;
    cin>>n;
    node* head=create(n);
    cout<<"linked list is"<<endl;
    print(head);
    head=reverse(head);
    cout<<"reversed linked list"<<endl;
    print(head);
}