#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans[200001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> heights;
    
    for(int i=0;i<n;i++){
        int next;
        cin>>next;
        heights.push_back(next);
    }
    cout<<setprecision(8);
    vector<int> distances;
    for(int i=0;i<n-1;i++){
        int next;
        cin>>next;
        distances.push_back(next);
    }
    for(int i=0;i<n;i++){
        if(i==0){
            cout<<-1<<" ";
        }
        else{
            cout<<ans[i]<<" ";
        }

        if(i==n-1){
            cout<<-1<<endl;
        }
        else{
            double slope = 0;
            int best = -1;
            int dis =0;
            for(int j=i+1;j<n;j++){
                dis+=distances[j-1];
                
                // cout<< heights[j]<<" "<<slope<<" "<<dis<<endl;
                if(best==-1||heights[j]>=slope*dis+heights[i]){
                    best = max(best,heights[j]);
                    ans[j] = max(ans[j], heights[i]);
                    slope = (double)(heights[j]-heights[i])/dis;
                }
            }
            cout<<best<<endl;
        }
    }
}