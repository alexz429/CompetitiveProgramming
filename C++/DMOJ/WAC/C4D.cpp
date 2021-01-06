#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    string in;
    cin>>in;
    string comp = "";
    for(int i=1;i<6000;i++){
        comp+=to_string(i);
    }
    // cout<<comp<<endl;
    for(int i=0;i<comp.length()-in.length();i++){
        if(comp.substr(i,in.length()).compare(in)==0){
            cout<<i+1<<endl;return 0;
        }
    }

}