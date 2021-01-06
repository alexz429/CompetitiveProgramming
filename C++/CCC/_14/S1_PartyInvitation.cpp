#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    map<int,int> test;
    test[0] = 0;

    pair<int,int> lmao = *test.begin();
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    list<int> store;
    for(int i=1;i<=n;i++){
        store.push_back(i);
    }
    for(int i=0;i<m;i++){
        int next;cin>>next;
        int tally = 0;
        for(list<int>::iterator it = store.begin();it!=store.end();it++){
            tally++;
            if(tally==next){
                // cout<<*it<<endl;
                tally = 1;
                it = store.erase(it);
                if(it==store.end())break;
            }
        }
    }
    for(int next: store){
        cout<<next<<endl;
    }

}