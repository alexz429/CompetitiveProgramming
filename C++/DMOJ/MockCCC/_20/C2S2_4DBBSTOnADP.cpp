#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

deque<char> output;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string in;
    cin>>in;
    output.push_back(in[0]);
    for(int i=1;i<n;i++){
        if(in[i]<=output.front()){
            output.push_front(in[i]);
        }
        else{
            output.push_back(in[i]);
        }
    }
    while(!output.empty()){
        cout<<output.front();
        output.pop_front();
    }
    cout<<"\n";
}