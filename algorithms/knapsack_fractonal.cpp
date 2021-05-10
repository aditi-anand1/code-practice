#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    cout<<"this program we are doing fractional knapsack"<<endl;
    cout<<"enter the number of input you want"<<endl;
    int n;
    cin>>n;
    vector<int>weight;
    vector<int>profit;
    for(int i=0;i<n;i++){
        cout<<"enter the weight and the coressponging profit"<<endl;
        int w,p;
        cin>>w>>p;
        weight.push_back(w);
        profit.push_back(p);
    }
    cout<<"enter the max weight"<<endl;
    int max_weight;
    cin>>max_weight;
    float frac;
    map<float,int>profit_box;
    for(int i=0;i<n;i++){
        frac=float(profit[i])/float(weight[i]);
        profit_box[frac]=weight[i];
        cout<<" =="<<frac<<endl;
    }
    int i,pro=0;
    map<float,int>::reverse_iterator itr;
    for(itr=profit_box.rbegin();itr!=profit_box.rend();itr++){
        int temp=itr->second;
        max_weight=max_weight-temp;
        for( i=0;i<n;i++){
            if(weight[i]==temp){
                break;
            }
        }

        if(max_weight<0){
            float te;
            te=(profit[i]*(max_weight+temp))/temp;
            pro=pro+te;
            break;
        }
        else{
        pro=pro+profit[i]; 
        }

    }
    cout<<pro;
}