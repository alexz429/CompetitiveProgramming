#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct  node{
    public:
    struct node* more[26];
};
string in;
int change = 1;
struct node* make(){
    struct node* next = new node;
    for(int i=0;i<26;i++){
        next->more[i]=NULL;
    }
    return next;
}
int add(node* head, int at, int shift){
    if(abs(shift)>=in.length()) return 0;
    int cur = in[(at+shift+in.length())%in.length()]-'a';
    int output=0;
    // cout<<cur<<endl;
    if(!head->more[cur]){
        // cout<<"oop"<<endl;
        head->more[cur] = make();
        output=add(head->more[cur], at, shift+=change)+1;
    }
    else{
        output = add(head->more[cur], at, shift+=change);
    }
    return output;
}
deque<char> construct(string in){
    deque<char> out;
    for(int i=0;i<in.length();i++){
        out.push_back(in[i]);
    }
    return out;
}

int a;
node* head = make();

int main(){
    
    cin>>a>>in;
    // cout<<"done"<<endl;
    int out=0;
    for(int i=0;i<in.length();i++){
        out+=add(head, i, 0);
    }
    change=-1;
    for(int i=0;i<in.length();i++){
        out+=add(head, i,0);
    }
    cout<<out;

}