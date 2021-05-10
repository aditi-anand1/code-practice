#include<iostream> 
using namespace std;
struct node{
    int data;
    int power;
    node* next;
};

node* creatingList(node* head, int n){
    node* ptr=head;
    while(n--){
        node* temp=new node();
        
        int cof,p;
        cout<<"Enter the coefficient and the power respectively"<<endl;
        cin>>cof>>p;
        temp->data=cof;
        temp->power=p;
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
int lengthOfList(node* head){
    node* ptr=head;
    int i=0;
    while(ptr!=NULL){
        i++;
        ptr=ptr->next;
    }
    return i;
}

node* addingPolynomial(node* head1, node* head2){
    int n1=lengthOfList(head1);
    int n2=lengthOfList(head2);
    node* long_ptr;
    node* short_ptr;
    node* head;
    if(n1>=n2){
        long_ptr=head1;
        head=head1;
        short_ptr=head2;
    }
    else{
        long_ptr=head2;
        head=head2;
        short_ptr=head1;
    }
    node* lp=long_ptr;
    while(short_ptr!=NULL){
        node* ptr=short_ptr->next;
        if(short_ptr->power>long_ptr->power){
            short_ptr->next=long_ptr;
            if(long_ptr==head){
                head=short_ptr;
            }
            lp->next=short_ptr;
            lp=lp->next;
            short_ptr=ptr;
        }
        else if(long_ptr->power>short_ptr->power){
            lp=long_ptr;
            long_ptr=long_ptr->next;
        }
        else {
            long_ptr->data=long_ptr->data+short_ptr->data;
            long_ptr=long_ptr->next;
            short_ptr=short_ptr->next;
        }
    }
   return head;
}

void print(node* head){
    node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"^"<<ptr->power<<" ";
        ptr=ptr->next;
    }
}
int main(){
    int s1,s2;
    node* head1=NULL;
    node* head2=NULL;
    cout<<"Enter the size of the polynomials respectively"<<endl;
    cin>>s1>>s2;
    head1=creatingList(head1,s1);
    print(head1);
    cout<<endl;
    cout<<"Your first polynomial list id done now enter the data for second list"<<endl;
    head2=creatingList(head2,s2);
    print(head2);
    cout<<endl;
    head1=addingPolynomial(head1,head2);
    print( head1);
    
}