#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<pair<int,int>>> skillz(k);
    int skills[k];
    pair<pair<int,int>,pair<int,int>> id[n];
    int index[k];
    fill(&index[0], &index[k], 0);
    fill(&id[0], &id[n], {{0,0},{0,0}});
    for(int i=0;i<k;i++){
        cin>>skills[i];
    }
    for(int i=0;i<k;i++){
        skillz[i] = vector<pair<int,int>>(n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            int next;
            cin>>next;
            skillz[k].emplace_back(next, i);
        }
    }
    // for(int i=0;i<k;i++){
    //     sort(skillz[i].begin(), skillz[i].end());
    // }
    // while(true){
    //     for(int i=0;i<k;i++){
    //         while(skills[i]>skillz[i][index[i]].first){
                
    //         int next = skillz[i][index[i]].second;
            
    //         }
    //     }
    // }


}