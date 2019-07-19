#include <bits/stdc++.h>
using namespace std;

int main(){
    string next;
    string kill="aeiouy";
    cin>>next;
    while(next.compare("quit!")!=0){
        if(next.length()<=4){
            // cout<<"ha";
            cout<<next<<endl;
            cin>>next;
            continue;
        }
        if(next.substr(next.length()-2,2).compare("or")!=0){
            cout<<next.substr(next.length()-2,2);
            // cout<<"hey";
            cout<<next<<endl;
            cin>>next;
            continue;
        }
        if(kill.find(next.at(next.length()-3))!=string::npos){
            // cout<<"ho";
            cout<<next<<endl;
            cin>>next;
            continue;
        }
        next=next.substr(0,next.length()-2)+"our";
        cout<<next<<endl;
        cin>>next;
    }
}