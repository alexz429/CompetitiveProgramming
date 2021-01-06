#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int left[n];
    int tally = 0;
    bool bat = true;
    for(int i=0;i<n;i++){
        cin>>left[i];
    }
    for(int i=0;i<n;i++){
        int next;
        cin>>next;
        if(left[i]==next){
            tally+=bat;
            bat = false;
        }
        else{
            bat = true;
        }
    }
    cout<<tally<<endl;
}