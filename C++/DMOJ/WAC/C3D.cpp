#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int parent[100000];
int vals[100000];
int oddEdges = 0;
int diffRegions = 0;
int findParent(int at){
    if(parent[at]==at||parent[at] == -1)return parent[at];
    return parent[at] = findParent(parent[at]);
}
void merge(int a, int b){
    parent[findParent(a)] = findParent(b);
}
bool connected(int a, int b){
    return findParent(a) == findParent(b);
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,q;
    cin>>n>>q;
    fill(&parent[0], &parent[n], -1);

    for(int i=0;i<q;i++){
        // cout<<i<<endl;
        int a,b,x;
        cin>>a>>b>>x;
        a--,b--;
        
        vals[a]+=x;
        vals[b]+=x;
        // for(int i=0;i<n;i++){
        //     cout<<vals[i]<<" ";
        // }
        // cout<<endl;
        if(x%2!=0){
            
        if(vals[a]%2==1){
            oddEdges++;
        }
        else{
            oddEdges--;
        }
        if(vals[b]%2==1){
            oddEdges++;
        }
        else{
            oddEdges--;
        }
        }
        if(findParent(a)==-1&&findParent(b)==-1){
            diffRegions++;
        }
        else if(!connected(a,b)&&findParent(a)!=-1&&findParent(b)!=-1){
            diffRegions--;
        }
        if(parent[a]==-1){
            parent[a] = a;
        }
        if(parent[b]==-1){
            parent[b] = b;
        }
        merge(a,b);
        // cout<<diffRegions<<" "<<oddEdges<<endl;    
        if(oddEdges>2||diffRegions>1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}