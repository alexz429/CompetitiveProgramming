#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int tree, ppl;
    cin>>tree>>ppl;
    vector<int> trees;
    for(int i=0;i<tree;i++){
        int next;
        cin>>next;
        trees.push_back(next);
    }
    sort(trees.begin(), trees.end());
    vector<pair<int,int>> lims;
    queue<pair<int,pair<int,ll>>> vals;
    for(int i=0;i<trees.size();i++){
        int l,r;
        if(i==0){
            l=-1;
        }
        else{
            l = (trees[i]-trees[i-1]-1)/2;
        }
        if(i==trees.size()-1){
            r=-1;
        }
        else{
            r = (trees[i+1]-trees[i])/2;
        }
        lims.push_back({l,r});
        // cout<<i<<" "<<l<<" "<<r<<endl;
        if(l!=0){
            vals.push({i,{-1,1}});
        }
        if(r!=0){
            vals.push({i,{1,1}});
        }
    }
    // cout<<"---------------"<<endl;
    vector<int> ans;
    ll tally = 0;
    for(int i=0;i<ppl;i++){
        pair<int,pair<int,ll>> next = vals.front();
        // cout<<next.first<<" "<<next.second.first<<" "<<next.second.second<<endl;
        vals.pop();
        
        ll loc = trees[next.first]+next.second.second*next.second.first;
        if(abs(loc)>2e9){
            continue;
        }
        tally+= next.second.second;
        // cout<<loc<<endl;
        ans.push_back(loc);
        int more;
        if(next.second.first==-1){
            more = lims[next.first].first;
        }
        else{
            more = lims[next.first].second;
        }
        if(more==-1||more>next.second.second){
            vals.push({next.first,{next.second.first, next.second.second+1}});
        }
    }
    cout<<tally<<endl;
    for(int next:ans){
        cout<<next<<" ";
    }
    cout<<endl;
}