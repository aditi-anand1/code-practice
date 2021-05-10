/**
 * Create a call log list which would display 10 recent calls.
 * Solved this using Queue.
 * @author 
 */
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;

struct node{
    long long number;
    string name;
    string date_time;
};

string Date();
void printing_call_log(queue<node*>call_log);
node* store_data(){
    node* info=new node();
    cout<<"Enter the name of person you want to call"<<endl;
    string name;
    cin>>name;
    info->name=name;
    cout<<"Enter the number of the person you want to call"<<endl;
    long long number;
    cin>>number;
    info->number=number;
    string date=Date();
    info->date_time=date;
    return info;
}

string Date(){
    time_t tt;
    
    struct tm* ti;
    
    time(&tt);
    ti=localtime(&tt);
    string a=asctime(ti);
    return a;
}

queue<node*> creating_log(queue<node*>call_log){
    node* info=store_data();
    call_log.push(info);
    if(call_log.size()>10){
        call_log.pop();
    }
    cout<<"Do you want to call again enter 1 if yes else enter 2 if you want to see your call log enter 3 if you dont want to do anything"<<endl;
    int call_choice_again;
    cin>>call_choice_again;
    if(call_choice_again==1){
        creating_log(call_log);
    }
    else if(call_choice_again==2){
        if(call_log.size()==0){
            cout<<"Call log is empty as no call is made yet"<<endl;
        }
        else{
        printing_call_log(call_log);
        }
        cout<<"enter 1 to continue enter 2 to exit"<<endl;
        int x;
        cin>>x;
        if(x==1){
            creating_log(call_log);
        }
    }
    else if(call_choice_again==3){
        return call_log;
    }
    else{
        cout<<"Invalid option"<<endl;
        return call_log;
    }
}

void printing_call_log(queue<node*>call_log){
    node* temp;
    cout<<"NAME : NUMBER :DAY MONTH  DATE TIME YEAR"<<endl;

    while (!call_log.empty()){
        temp=call_log.front();
        cout<<temp->name<<" : "<<temp->number<<" : "<<temp->date_time<<endl;
        call_log.pop();
        free(temp);
    }
}
int main(){
    queue<node*>call_log;
    cout<<"Welcome enter 1 if you want to call or enter 2 if you dont want to call"<<endl;
    int call_choice;
    cin>>call_choice;
    if(call_choice==2){
        cout<<"NO calls are made so your call log is empty"<<endl;
    }
    else{
        call_log=creating_log(call_log);
    }
    
  cout<<"Thank you "<<endl;  
}