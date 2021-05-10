

#include <iostream>

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

node* sort(node* head){
    node* ptr=head;
    int temp;
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
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main()
{
   int n;
   cout<<"number of elements you want in your list"<<endl;
     cin>>n;
     node* head=create(n);
     cout<<"before sorting your list look like this"<<endl;
     print(head);
     cout<<endl;
     head=sort(head);
     cout<<"sorting done"<<endl;
     print(head);
  

    return 0;
}
