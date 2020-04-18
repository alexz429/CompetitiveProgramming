#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        int test = 0;
        int sum  = 0;
        for(int j=0;j<m;j++){
            int next;
            cin>>next;
            if(next%2==0){
                test|=1;
            }
            if(next%2==1){
                test|=2;
            }
            sum+=next;
        }
        if(sum%2==1||test==3){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}