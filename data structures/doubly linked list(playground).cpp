#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};

node* insert_beg(node* head){
    node* temp=new node();
    cout<<"what value u want to enter"<<endl;
    int dat;
    cin>>dat;
    temp->data=dat;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    return head;
}

node* insert_end(node* head){
    node* ptr=head;
    node* temp=new node();
    cout<<"what value u want to enter"<<endl;
    int dat;
    cin>>dat;
    temp->data=dat;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        head=temp;
        ptr=head;
    }
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    }
    return head;
    
}
node* insert_mid(node* head){
     node* ptr=head;
     int where;
    node* temp=new node();
    cout<<"what value u want to enter"<<endl;
    int dat;
    cin>>dat;
    temp->data=dat;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL){
        head=temp;
        ptr=head;
    }
    else{
        cout<<"after which number u want to insert"<<endl;
        cin>>where;
        while(ptr->data!=where){
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        temp->prev=ptr;
        ptr->next=temp;
        ptr=temp->next;
        ptr->prev=temp;
    }
    return head;
}

node* del_beg(node* head){
    node* ptr=head;
    if(head==NULL){
        cout<<"cant do anything the list already empty"<<endl;
        return head;
    }
     else if(ptr->next==NULL){
        head=NULL;
    }
    else{
    head=ptr->next;
    head->prev=NULL;
    return head;
        
    }
}

node* del_end(node* head){
    node* ptr=head;
    node* ptr1=head;
     if(head==NULL){
        cout<<"cant do anything the list already empty"<<endl;
        return head;
    }
    else if(ptr->next==NULL){
        head=NULL;
    }
    else{
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        ptr1=ptr->next;
        ptr1->prev=NULL;
        ptr->next=NULL;
    }
    return head;
}
node* del_mid(node* head){
    int i=0,j=0;
    node* ptr=head;
    node* ptr1=head;
     if(head==NULL){
        cout<<"cant do anything the list already empty"<<endl;
        return head;
    }
     else if(ptr->next==NULL){
        head=NULL;
    }
    else{
        while(ptr!=NULL){
            i++;
            ptr=ptr->next;
        }
        ptr=head;
        if(i%2==0){
            i=i/2;
        }
        else{
            i=(i+1)/2;
        }
        while(j!=i){
            ptr=ptr->next;
            j++;
        }
        ptr1=ptr->prev;
        ptr=ptr->next;
        ptr1->next=ptr;
        ptr->prev=ptr1;
     return head;
}
}

node* del_position(node* head){
    node* ptr=head;
    node* ptr1=head;
     if(head==NULL){
        cout<<"cant do anything the list already empty"<<endl;
        return head;
    }
     else if(ptr->next==NULL){
        head=NULL;
    }
    else{
        cout<<"what u want to delete"<<endl;
        int what;
        cin>>what;
        while(ptr->data!=what){
            ptr=ptr->next;
        }
         ptr1=ptr->prev;
        ptr=ptr->next;
        ptr1->next=ptr;
        ptr->prev=ptr1;
     return head;
        
    }
}

void check(node* head){
  
    node* ptr=head;
    if(head==NULL){
        cout<<"list is empty there is nothing to search ";
        return;
    }
    else{
          int search;
    cout<<"enter the number you want to search"<<endl;
    cin>>search;
    while(ptr!=NULL){
        if(ptr->data==search){
            cout<< "Yes the number is present";
            return;
        }
        ptr=ptr->next;
    }
    cout<< "No the number you are searching for is not present";
    }
}

void print_before(node* head){
    node* ptr=head;
    
    if(head==NULL){
        cout<<"list is empty there is nothing to search" <<endl;
    }
    else{
        int search;
    cout<<"enter the number you want to search and print all the number befor that"<<endl;
    cin>>search;
        while(ptr!=NULL){
            if(ptr->data==search){
                break;
            }
            ptr=ptr->next;
        }
        if(ptr==NULL){
            cout<<"this number doesnot exist"<<endl;
        }
        else{
        while(ptr!=NULL){
            cout<<ptr->data;
            ptr=ptr->prev;
        }}
    }
}
void print_after(node* head){
      node* ptr=head;
    
    if(head==NULL){
        cout<<"list is empty there is nothing to search" <<endl;
    }
    else{
        int search;
    cout<<"enter the number you want to search and print all the number after that"<<endl;
    cin>>search;
          while(ptr!=NULL){
            if(ptr->data==search){
                break;
            }
            ptr=ptr->next;
        }
        if(ptr==NULL){
            cout<<"this number doesnot exist"<<endl;
        }
        else{
        while(ptr!=NULL){
            cout<<ptr->data;
            ptr=ptr->next;
        }}
    }
}

void print_result(node* head){
    node* ptr=head;
    cout<<"so your final list is"<<endl;
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

int main(){
    node* head=NULL;
    string result;
    cout<<"welcome to the game to linked list"<<endl;
    int n;
    cout<<"how many times u want to do the operations"<<endl;
    cin>>n;
    while(n--){
    cout<<"choose 1 if u want to insert any number"<<endl;
    cout<<"choose 2 if u want to delete any number"<<endl;
    cout<<"choose 3 if u want to search anynumber"<<endl;
    int first_choice,second_choice;
    cin>>first_choice;
    switch(first_choice){
        case 1:
        cout<<"so u have chose to insert a value now give some more info"<<endl;
        cout<<"choose 1 if u want to insert in the beginnig"<<endl;
        cout<<"choose 2 if u want to insert int the end"<<endl;
        cout<<"choose 3 if u want to insert int the middle"<<endl;
        cin>>second_choice;
            switch(second_choice){
                case 1:
                head=insert_beg(head);
                    break;
                case 2:
                head=insert_end(head);
                    break;
                case 3:
                head=insert_mid(head);
                    break;
                default:cout<<"you have choose the invaild option"<<endl;
                     break;
            }
        break;
        case 2:
        cout<<"so u have chose to delete a value now give some more info"<<endl;
        cout<<"choose 1 if u want to delete in the beginnig"<<endl;
        cout<<"choose 2 if u want to delete int the end"<<endl;
        cout<<"choose 3 if u want to delete int the middle"<<endl;
        cout<<"choose 4 if u wan to delete at any specific postion"<<endl;
        cin>>second_choice;
            switch(second_choice){
                case 1:
                head=del_beg(head);
                    break;
                case 2:
                head=del_end(head);
                    break;
                case 3:
                head=del_mid(head);
                    break;
                case 4:
                head=del_position(head);
                    break;
                default:cout<<"you have choose the invaild option"<<endl;
                    break;
                
            }
        break;
        case 3:
        cout<<"so you have chose to search a value so give us some more info"<<endl;
        cout<<"choose 1 if u want to knw the value exists or not"<<endl;
        cout<<"choose 2 if u want to print all the previous values from  thr existing values"<<endl;
        cout<<"choose 3 if u want to print all the next values fro  thr existing values"<<endl;
        cin>>second_choice;
            switch(second_choice){
                case 1:
                    check(head);
                    break;
                case 2:
                    print_before(head);
                    break;
                case 3:
                print_after(head);
                    break;
                default:cout<<"you have choose the invaild option"<<endl;
                    break;
            }
        break;
        default:cout<<"you have choose the invaild option"<<endl;
            break;
    }
    }
    print_result(head);

}