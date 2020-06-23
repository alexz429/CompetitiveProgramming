#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<string,int,int,int> tp;

struct computer{
    int R;
    int S;
    int D;
    string name;
};

struct computer* makeComputer(){
    struct computer* newItem = (struct computer*) malloc(sizeof(struct computer));
    newItem->R = 0;
    newItem->S = 0;
    newItem->D = 0;
    newItem->name = "";
}

bool comp(tp a, tp b){
    int val = get<1>(a) * 2 + get<2>(a)*3+ get<3>(a);
    int val2 = get<1>(b) * 2 + get<2>(b)*3+ get<3>(b);
    if(val==val2){
        return get<0>(a).compare(get<0>(b))<0;
    }
    else{
        return val>val2;
    }
}


int main(){
    int n;
    cin>>n;
    tp input[n];
    for(int i=0;i<n;i++){
        string a;int b,c,d;
        cin>>a>>b>>c>>d;
        input[i] = {a,b,c,d};
    }
    if(n==1){
    cout<<get<0>(input[0])<<endl;
    return 0;
    }
    sort(&input[0], &input[n], comp);
    cout<<get<0>(input[0])<<endl;
    cout<<get<0>(input[1])<<endl;
}