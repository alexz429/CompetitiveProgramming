#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(string a, string b){
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[a.length()-1-i]){
            return false;
        }
    }
    return true;
}
bool single(string a){
    for(int i=0;i<a.length()/2;i++){
        if(a[i]!=a[a.length()-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    string vals[n];
    for(int i=0;i<n;i++){
        cin>>vals[i];
    }
    bool used[n];
    fill(&used[0], &used[n], 0);
    string out = "";
    queue<string> left;
    queue<string> right;
    for(int i=0;i<n;i++){
        if(used[i])continue;
        bool yeet = false;
        for(int j=i+1;j<n;j++){
            if(used[j])continue;
            if(check(vals[i], vals[j])){
                left.push(vals[i]);
                right.push(vals[j]);
                used[i]=true;
                used[j]=true;
                yeet = true;
                break;
            }
        }
        if(!yeet){
            if(single(vals[i])&&out.length()<1){
                out = vals[i];
            }
        }
    }
    while(!left.empty()){
        out = left.front()+ out+right.front();
        left.pop();
        right.pop();
    }
    cout<<out.length()<<endl;
    cout<<out<<endl;
}