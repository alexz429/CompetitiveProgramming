#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define LIM 127
int parent[LIM+1][50000];

int getParent(int* parents, int a){
    if(parents[a] == a)return a;
    return parents[a] = getParent(parents, parents[a]);
}

bool isConnected(int* parents, int a, int b){
    return getParent(parents, a) == getParent(parents, b);
}
void merge(int* parents, int a, int b){
    parents[getParent(parents, a)] = getParent(parents, b);
}
void bigMerge(int weight, int a, int b){
    for(int i=weight;i<=LIM;i++){
        if((weight&i)==weight){
            merge(parent[i], a,b);
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<=LIM;i++){
        for(int j=0;j<n;j++){
            parent[i][j] = j;
        }
    }
    for(int i=0;i<m;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        from--;to--;
        bigMerge(weight, from,to);
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        for(int j=0;j<=LIM;j++){
            if(isConnected(parent[j], a,b)){
                cout<<j<<endl;
                break;
            }
        }
    }
}