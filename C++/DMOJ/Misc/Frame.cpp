#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin>>h>>w;
    for(int count=0;count<w+2;count++){
        cout<<"#";
    }
    cout<<endl;
    for(int count=0;count<h;count++){
        string next;
        cin>>next;
        cout<<"#"<<next<<"#"<<endl;
    }
    for(int count=0;count<w+2;count++){
        cout<<"#";
    }
    cout<<endl;
}