#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int max;
    cin>>max;
    int vals[max];
    for(int i=0;i<max;i++){
        int cost, rev;
        cin>>cost>>rev;
        int diff = rev-cost;
        vals[i] = diff;
    }
    int l=max-1;
    int sum =0;
    int obstacle = 0;
    for(int i=0;i<max;i++){
        sum+=vals[i];
        while(sum<0&&obstacle<0){
            l--;
            sum+=vals[i];
            obstacle = min(0,obstacle+vals[i]);
        }
        if(i>=sum){
            cout<<sum<<endl;
            return 0;
        }
    }

}