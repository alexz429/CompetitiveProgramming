#include <bits/stdc++.h>
using namespace std;
typedef long long ll;bool aux[200004];

int parent[200004];
int getParent(int a){
    if(parent[a]==a){
        return a;
    }
    return parent[a]=getParent(parent[a]);
}
int merge(int from, int to){
    parent[getParent(from)] = getParent(to);
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int num;
    cin>>num;
    vector<int> wires;
    
    for(int i=0;i<num-1;i++){
        
        int next;
        cin>>next;
        wires.push_back(next);
        aux[next]=true;
    }    
    set<int> huh;
    for(int i=1;i<=num;i++){
        parent[i]=i;
        if(!aux[i]){
            huh.insert(i);
        }
    }
    cout<<wires[0]<<endl;
    for(int i=num-2;i>=0;i--){
        
        // cout<<"end"<<endl;
        cout<<wires[i]<<" "<<getParent(*huh.begin())<<endl;
        
        int val = *huh.begin();
        merge(val, wires[i]);
        huh.erase(huh.begin());
        if(getParent(val)!=wires[0]){
        huh.insert(max(val,wires[i]));
        }
    }

}