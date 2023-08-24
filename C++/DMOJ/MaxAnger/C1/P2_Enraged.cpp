#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool arr[2][200005];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        char next;cin>>next;
        arr[0][i] = next == 'S';
    }
    for(int i=0;i<a;i++){
        char next;cin>>next;
        arr[1][i] = next == 'S';
    }
    int tally = 0;
    for(int i = 0;i<a;i++){
        if(arr[0][i]&&arr[1][i]){
            tally++;   
        }
    }
    if(tally > 2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}