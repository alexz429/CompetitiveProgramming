#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    int index=0;
    // string input;
    struct node* children[26];
};
int nextIndex = 1;
typedef struct node Node;
Node* mkNode(int inputIndex){
    Node* newNode = (Node*) malloc(sizeof(Node));
    // cout<<&newNode<<endl;
    // cout<<"um"<<endl;
    newNode->index = inputIndex;
    // cout<<"what"<<endl;
    for(int i=0;i<26;i++){
        // cout<<i<<endl;
        newNode->children[i] = NULL;
    }
    return newNode;  
}
Node* init(Node* cur,string in, int at){
    if(at>=in.length()){
        // cur->input=in;
        return cur;
    }
    int index = in[at]-'a';
    if(!cur->children[index]){
        cur->children[index] = mkNode(0);
    }
    return init(cur->children[index], in, at+1);
}
Node* add(Node* cur, string in){
    int index = in[0]-'a';
    // cout<<"adding "<<index<<" at "<<cur->input<<endl;
    
    if(!cur->children[index]){
        // cout<<"make new"<<endl;
        Node* huh = mkNode(nextIndex);
        // cout<<"set"<<endl;
        cur->children[index] = huh;
        
        // cur->children[index]->input = cur->input+in;
    }
    // cout<<"done"<<endl;
    return cur->children[index];
}
int query(Node* cur, string in, int at){
    // cout<<cur->index<<" "<<in[at]<<endl;
    int index = in[at]-'a';
    if(cur->children[index]){
        // cout<<"found"<<endl;
        if(at+1<in.length()){
            return query(cur->children[index], in, at+1);
        }
        return cur->children[index]->index;
    }
    else{
        // cout<<"oof"<<endl;
        return cur->index;
    }
}
int comp(string a, string b){
    int i=0;
    for(;i<min(a.length(), b.length());i++){
        if(a[i]!=b[i]){
            return i-1;
        }
    }
    return i-1;
}
Node* pointers[100005];
Node* head;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    head = mkNode(0);
    string s;
    int q;
    cin>>s>>q;
    pointers[0] = head;
    for(int i=0;i<q;i++){
        string com;
        cin>>com;
        if(com[0]=='C'){
            int a;
            cin>>a;
            string b;
            cin>>b;
            a--;
            pointers[nextIndex] = add(pointers[a], b);
            nextIndex++;
            // for(int j=0;j<nextIndex;j++){
            //     cout<<pointers[j]->index<<" ";
            // }
            // cout<<endl;
        }
        else{
            string q;
            
            cin>>q;
            if(comp(q,s)==s.length()-1){
                string test = q.substr(0,s.length());
                if(test.compare(s)==0){
                    cout<<query(head, q.substr(s.length()),0)+1<<"\n";
                }
                else{
                    cout<<-1<<"\n";
                }
            }
            else if(comp(q,s)>-1){
                cout<<1<<"\n";
            }
            else{
                cout<<-1<<"\n";
            }
        }
    }
}