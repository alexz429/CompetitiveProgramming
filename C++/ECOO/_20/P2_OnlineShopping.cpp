#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int m; cin>>m;
        map<string,vector<pair<int,int>>> items;
        for(int j=0;j<m;j++){
            int l;cin>>l;
            for(int k=0;k<l;k++){
                
            string next; int p, q;
            cin>>next>>p>>q;
            if(items.find(next)==items.end()){
                items[next] = vector<pair<int,int>>(120);
            }
            items[next].push_back({p,q});
            }
        }
        int k;cin>>k;
        int tally = 0;
        for(int j=0;j<k;j++){
            string next; int amount;
            cin>>next>>amount;
            vector<pair<int,int>> item = items[next];
            sort(item.begin(),item.end());
            int index = 0;
            while(amount>0){
                pair<int,int> take = item[index++];
                tally+= take.first*min(take.second, amount);
                amount-=min(take.second, amount);
            }
        }
        cout<<tally<<endl;
    }
}