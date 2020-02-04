#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cow[100000];
int parent[100000];

int findParent(int a){
    if(parent[a]==a){
        return a;
    }
    return parent[a] = findParent(parent[a]);
}
bool isConnected(int a, int b){
    return findParent(a) == findParent(b);
}

void connect(int a, int b){
    parent[findParent(a)] = findParent(b);
}


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    for(int i=0;i<n;i++){
        cin>>cow[i];
    }
    for(int i=0;i<n-1;i++){
        int from, to;
        cin>>from>>to;
        from--;to--;
        if(cow[from] == cow[to]){
            connect(from, to);
        }
    }
    string output = "";
    for(int i=0;i<m;i++){
        int from, to, yeet;
        cin>>from>>to>>yeet;
        from--;to--;
        if(!isConnected(from,to)){
            output+="1";
        }
        else{
            if(yeet ==cow[from]){
                output+="1";
            }
            else{
                output+="0";
            }
        }
    }
    cout<<output<<"\n";
}