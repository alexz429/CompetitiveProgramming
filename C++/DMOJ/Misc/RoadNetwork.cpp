#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int loc[1001][2];
int connect[1001];
int findParent(int at){
    if(connect[at]==at)return at;
    return connect[at]= findParent(connect[at]);
}
bool connected(int a, int b){
    return findParent(a) == findParent(b);
}
void merge(int a, int b){
    connect[findParent(a)] = findParent(b);
}
double len(int a, int b){
    return sqrt(pow(loc[a][0]-loc[b][0],2)+pow(loc[a][1]-loc[b][1],2));
}

// vector<vector<pair<int,double>>> graph;
int nodes, edges, a,b;
int main(){
    auto cmp = [](int a, int b){return len(a%10000,a/10000)<len(b%10000,b/10000);};
vector<int> pq;    
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int nodes, edges;
    cin>>nodes>>edges;
    for(int i=0;i<nodes;i++){
        connect[i]=i;
    }
    for(int count=1;count<=nodes;count++){
        cin>>loc[count][0]>>loc[count][1];
        for(int i=1;i<count;i++){
            pq.emplace_back(count*10000+i);
        }
        
    }
    for(int i=0;i<edges;i++){
        cin>>a>>b;
        merge(a,b);
    }
    sort(begin(pq),end(pq),cmp);
    double output=0;
    for(int next:pq){
        // cout<<len(pq[i]%10000,pq[i]/10000)<<endl;
        if(connected(next%10000,next/10000))continue;
        output+=len(next%10000,next/10000);
        merge(next%10000,next/10000);
    }
    std::cout<<fixed<<setprecision(2)<<output;


}