#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int max;
    cin>>max;
    int beans[max];
    int best = -1;
    for(int i=0;i<max;i++){
        cin>>beans[i];
    }
    for(int i=0;i<max;i++){
        int next;
        cin>>next;
        if(best==-1){
            best = beans[i]/next;
        }
        else{
            best = min(best, beans[i]/next);
        }
    }
    cout<<best<<endl;
}