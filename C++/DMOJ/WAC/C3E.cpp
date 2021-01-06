#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> vals;
ll best = 0;
int n = 0;
int findNext(int curIndex){
    while(curIndex<vals.size()&&vals[curIndex].first==-1){
        curIndex++;
    }
    if(curIndex>vals.size()-1){
        return -1;
    }
    return curIndex;
}
void recurse(ll tally){
    if(tally>best)return;
    // for(int i=0;i<n;i++){
    //     cout<<vals[i].first<<" ";
    // }
    // cout<<endl;
    int a[3];
    for(int i=0;i<3;i++){
        a[i] = findNext((i==0)?0:(a[i-1]+1));
        if(a[i]==-1){
            // cout<<"A"<<endl;
            best = min(best, tally);
            return;
        }
    }
    bool wrong = false;
    while(true){
        if(vals[a[0]].first+vals[a[1]].first>vals[a[2]].first){
            // cout<<"JUDGING"<<vals[a[0]].first<<" "<<vals[a[1]].first<<" "<<vals[a[2]].first<<endl;
            wrong = true;
            for(int i=0;i<3;i++){
             
            int temp = vals[a[i]].first;
            vals[a[i]].first=-1;
            recurse(tally+vals[a[i]].second);
            vals[a[i]].first = temp;
           
            }
            return;
        }
        a[0] = a[1];
        a[1] = a[2];
        a[2] = findNext(a[2]+1);
        if(a[2]==-1){
            // cout<<"B"<<endl;
            if(!wrong){
                
            best = min(best, tally);
            }
            return;
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int l,v;
        cin>>l>>v;
        vals.push_back({l,v});
        best+=v;
    }
    sort(vals.begin(), vals.end());
    recurse(0);
    cout<<best<<endl;

}