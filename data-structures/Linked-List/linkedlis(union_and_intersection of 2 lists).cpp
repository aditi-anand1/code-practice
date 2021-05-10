#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};

node* list_making(node* head,int n){
     node* ptr=head;
    node* temp=new node();
    temp->data=n;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        ptr=head;
        }
    else{
          temp->next=head;
          head=temp;
        }
  return head;  
}


void print(node* head){
    node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

node* intersection(node* head1,node* head2){
    node* intersection_head=NULL;
    node* ptr1=head1;
    while(ptr1!=NULL){
          node* ptr2=head2;
        while(ptr2!=NULL){
            if(ptr1->data==ptr2->data){
                intersection_head=list_making(intersection_head,ptr1->data);
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    
    return intersection_head;
}

node* union_list(node* head1,node* head2){
    node* ptr1=head1;
    node* ptr2=head2;
    while(ptr2!=NULL){
        ptr1=head1;
        while(ptr1!=NULL){
            if(ptr1->data!=ptr2->data){
                head1=list_making(head1,ptr1->data);
            }
            ptr1=ptr1->next;
        }
        ptr2=ptr2->next;
    }
    return head1;
}
int main(){
    cout<<"This code is to find the Union and Intersection of two Linked Lists"<<endl;
    int l1,l2;
    cout<<"Enter the size of the first list"<<endl;
    cin>>l1;
    node* head1=NULL;
    while(l1--){
        int element;
        cout<<"enter the element you want in your list"<<endl;
        cin>>element;
       head1=list_making(head1,element);
    }
    
    cout<<"Enter the size of the second list"<<endl;
    cin>>l2;
    node* head2=NULL;
    while(l2--){
        int element;
        cout<<"enter the element you want in your list"<<endl;
        cin>>element;
       head2=list_making(head2,element);
    }
    
    cout<<"So your first list is:-"<<endl;
    print(head1);
    cout<<"So your second list is:-"<<endl;
    print(head2);
    cout<<"Intersection of the two list is"<<endl;
    node* intersection_head=intersection(head1,head2);
    print(intersection_head);
    cout<<"Union of the two lists are"<<endl;
    head1=union_list(head1,head2);
    print(head1);
}
    
    