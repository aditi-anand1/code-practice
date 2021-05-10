#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};

node* create(node* head,int n){
    int data;
    node* ptr=head;
    while(n--){
        node* temp=new node();
        temp->next=NULL;
        cout<<"enter the element"<<endl;
        cin>>data;
        temp->data=data;
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

int compare(node* head1,node* head2){
    node* ptr1=head1;
    node* ptr2=head2;
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->data!=ptr2->data){
            if(ptr1->data>ptr2->data){
                return 1;
            }
            else {
                return -1;
            }
            
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
      
    }
    if(ptr1==NULL&&ptr2==NULL){
        return 0;
    }
    else if(ptr1!=NULL&&ptr2==NULL){
        return 1;
    }
    else {
        return -1;
    }
}
int main(){
    int n1,n2;
    cout<<"Enter the number of element in first list"<<endl;
    cin>>n1;
    node* head1=NULL;
    node* head2=NULL;
    head1=create(head1,n1);
    cout<<"Enter the number of element in second list"<<endl;
    cin>>n2;
    head2=create(head2,n2);
    int x=compare(head1,head2);
    if(x==0){
        cout<<"Both linked list are same"<<endl;
    }
    else if(x==1){
        cout<<"Linked list 1 is lexicographically greater"<<endl;
    }
    else if(x==-1){
        cout<<"Linked list 2 is lexicographically greater"<<endl;
    }
    
    
    
}