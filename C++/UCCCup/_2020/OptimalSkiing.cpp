#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    int best = -1;
    for(int i=0;i<n;i++){
        int next;
        cin>>next;
        int sum = 0;
        for(int j=0;j<next;j++){
            int total=0;
            cin>>total;
            sum+=total;
        }
        if(best==-1||best>sum){
            best = sum;
        }
    }
    cout<<best<<endl;
}