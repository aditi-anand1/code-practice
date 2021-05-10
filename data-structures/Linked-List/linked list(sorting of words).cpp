
#include<iostream>
using namespace std;
struct node{
    string data;
    node* next;
};
node* create(int n){
    node* head=NULL;
    node* ptr=head;
    while(n--){
        node* temp=new node;
        string dat;
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

node* sort(node* head){
    string temp;
    node* ptr=head;
    node* ptr1=ptr->next;
    while(ptr->next!=NULL){
        while(ptr1!=NULL){
            if(ptr->data>ptr1->data){
                temp=ptr->data;
                ptr->data=ptr1->data;
                ptr1->data=temp;
            }
           ptr1=ptr1->next;
        }
         ptr=ptr->next;
            ptr1=ptr->next;
    }
    return head;
}
void print(node* head){
    node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"  ";
        ptr=ptr->next;
    }
}
int main(){
    int n;
    cout<<"tell the number of input you want"<<endl;
    cin>>n;
    node* head=create(n);
    cout<<"list before sorting"<<endl;
    print(head);
    head=sort(head);
    cout<<endl;
    cout<<"list after sorting"<<endl;
    print(head);
    
}