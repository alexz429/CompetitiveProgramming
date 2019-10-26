#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> stuff;
queue<pair<int, int>> mono;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int l,r;
    cin>>l>>r;
    int diff = abs(l-r);
    // printf("hi");
    stuff.emplace_back(vector<int>());
    stuff.emplace_back(vector<int>());
    int index = 0;
    for(int i=0;i<l;i++){
        int next;
        cin>>next;
        stuff[0].emplace_back(next);
    }
    for(int i=0;i<r;i++){
        int next;
        cin>>next;
        stuff[1].emplace_back(next);
    }
    if(l>r){
        index = 1;
    }
    
    sort(stuff[0].begin(), stuff[0].end());
    sort(stuff[1].begin(), stuff[1].end());
    // printf("%d\n", index);
    int small = 0;
    int big = 1e9+1;
    while(small!=big){
        // printf("%d %d\n", small, big);
        int mid = (small+big)/2;
        int other = 0;
        bool flag = true;
        for(int i=0;i<stuff[index].size();i++, other++){
            // printf("%d\n", i);
            if(other>=stuff[index^1].size()){
                flag = false;
                break;
            }
            while(abs(stuff[index][i]-stuff[index^1][other])>mid){
                if(++other>=stuff[index^1].size()){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            big = mid;
        }
        else{
            small = mid+1;
        }
    }
    printf("%d\n", big);
}