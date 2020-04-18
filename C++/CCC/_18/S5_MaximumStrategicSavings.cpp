#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int hori[100000];
int verti[100000];



int findParent(int a, int* array){
    if(array[a] == a ) return a;
    return array[a] = findParent(array[a], array);
}

bool isConnected(int a, int b, int* array){
    // cout<<findParent(a, array) <<" "<< findParent(b, array)<<endl;
    return findParent(a, array) == findParent(b, array);
}

void merge(int a, int b, int* array){
    array[findParent(a, array)] = findParent(b, array);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m,p,q;
    
    set<pair<pair<int,int>, pair<int,int>>> stuff;
    // cout<<((*stuff.begin()).first.first)<<endl;
    cin>>n>>m>>p>>q;
    for(int i=0;i<n;i++){
        verti[i] = i;
    }
    for(int i=0;i<m;i++){
        hori[i] = i;
    }
    ll prev = 0;
    for(int i=0;i<p;i++){
        int a,b,c;
        cin>>a>>b>>c;
        stuff.insert({{c, 0}, {a,b}});
        prev+=(ll)c*(ll)n;
    }
    for(int i=0;i<q;i++){
        int a,b,c;
        cin>>a>>b>>c;
        stuff.insert({{c, 1}, {a,b}});
        prev+=(ll)c*(ll)m;
    }
    ll cost = 0;
    while(stuff.size()>0){
        pair<pair<int,int>, pair<int,int>> next = *stuff.begin();
        // cout<<next.first.first<<" "<<next.second.first<<" "<<next.second.second<<endl;
        
        if(next.first.second == 0){
            if(!isConnected(next.second.first, next.second.second, hori)){
                cost += (ll)n*(ll)next.first.first;
                m--;
                merge(next.second.first, next.second.second, hori);
            }
        }
        else{
            if(!isConnected(next.second.first, next.second.second, verti)){
                cost+= (ll)m*(ll)next.first.first;
                n--;
                merge(next.second.first, next.second.second, verti);
            }
        }
        // cout<<cost<<endl;
        stuff.erase(stuff.begin());
    }
    cout<<prev-cost<<endl;
}