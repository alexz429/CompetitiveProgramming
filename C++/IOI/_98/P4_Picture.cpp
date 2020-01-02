#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct E{int a,b1,b2,adj;};
bool cmp(E a, E b){return a.a<b.a||(a.a==b.a&&a.adj>b.adj);}
const int adjust = 1e4+1;
int states[2*adjust];
ll answer(vector<E> event){
    int ans=0;
    for(E next: event){
        if(next.adj==1){
            for(int i=next.b1;i<next.b2;i++){
                if(states[i]==0){
                    ans++;
                }
                states[i]++;
            }
        }
        else{
            for(int i=next.b1;i<next.b2;i++){
                states[i]--;
                if(states[i]==0){
                    ans++;
                }
            }
        }
    }
    return ans;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    /*
        take every side of rectangle as an event with x, y1, y2, val
        where val is +1 for starting sides and -1 for ending sides

        repeat for the y values by y, x1, x2, val

        for each of these events build a segtree that adds that specific range, before counting the number of zeroes
        for starting, count before add, for endings, count after add.

        repeat for y values
    */
   int n;
    cin>>n;
    vector<E> horiEvents;
    vector<E> vertiEvents;
    for(int i=0;i<n;i++){
        int x,y,x2,y2;
        cin>>x>>y>>x2>>y2;
        x+=adjust;
        x2+=adjust;
        y+=adjust;
        y2+=adjust;
        horiEvents.push_back(E{x,y,y2,1});
        horiEvents.push_back(E{x2,y,y2,-1});
        vertiEvents.push_back(E{y,x,x2,1});
        vertiEvents.push_back(E{y2,x,x2,-1});
    }
    sort(horiEvents.begin(), horiEvents.end(), cmp);
    sort(vertiEvents.begin(), vertiEvents.end(), cmp);
    cout<<answer(horiEvents)+answer(vertiEvents)<<endl;
}