#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
vector<int> starts;
int process(){
int low = 1;
    int high = m;
    int out = 0;
    int mid;
    while(low!=high){
        // cout<<low<<" "<<high<<endl;
        mid = (low+high)/2;
        int det = 0;
        
        for(int next: starts){
            int flip=0;
            if(next==mid||(m%2==0&&(mid+m/2)%m==next))continue;
            if(next<mid){
                flip = -1;
            }
            else{
                flip =1;
            }
            if(abs(next-mid)>m/2){
                flip*=-1;
            }
            det+=flip;
        }
        if(det == 0){
            out = mid;
            break;
        }
        else if(det>0){
            low = mid+1;
        }
        else{
            high = mid;
        }
        out = high;
    }
    return out;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int next;
        cin>>next;
        starts.push_back(next);
    }
    int out = process();
    // cout<<"ans"<<out<<endl;
    ll output = 0;
    for(int next: starts){
        output += (min(abs(next-out), min(abs(out+m-next), abs(next+m-out))));
    }
    for(int i=0;i<n;i++){
        starts[i]= (starts[i]+(m/2))%m;
    }
    int out2 = process();
    
    ll output2 =0;
    
    for(int next: starts){
        output2 += (min(abs(next-out2), min(abs(out2+m-next), abs(next+m-out2))));
    }
    cout<<min(output,output2)<<endl;
    
}