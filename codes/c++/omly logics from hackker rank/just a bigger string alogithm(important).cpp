https://www.nayuki.io/page/next-lexicographical-permutation-algorithm

this is very important algorithm to find just a bigger number or a string and its is very common question in the placement and below is the ques from hackker rank based on this algorithm

https://www.hackerrank.com/challenges/bigger-is-greater/problem?isFullScreen=false

int down(string w){
    int len=w.size();
    while(len--){
        if(w[len]>w[len-1]){
            break;
        }
    }
    cout<<len-1<<" "<<w[len-1]<<endl;;
    return len-1;
}
int second_down(int x, string w){
    int len=w.size();
    int check=x;
    
    while(check<len){
        if((w[x]>=w[check])&&(x!=check)){
            check=check-1;
            cout<<check<<" "<<w[check]<<endl;
            return check;
        }
        else if((check==len-1)&&(w[x]<w[check])){
            return check;
        }
        check++;
    }
    return 1;
}
string modified(string w,int x,int check){
    char temp;
    temp=w[x];
    w[x]=w[check];
    w[check]=temp;
    cout<<w;
    return w;
}
string reversing(string w,int x){
    reverse(w.begin()+x+1,w.end());
    return w;
}
string biggerIsGreater(string w) {
    int x=down(w);
    if(x==-1){
        return "no answer";
    }
    int check=second_down(x,w);
    w=modified(w,x,check);
    w=reversing(w,x);
    return w;
}

