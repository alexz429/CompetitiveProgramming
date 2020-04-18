#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define LIMIT 1000001
bool sieve[LIMIT];
void init(){
    for(int i=2;i<LIMIT;i++){
        if(!sieve[i]){
            for(int j=2;i*j<LIMIT;j++){
                sieve[i*j]=true;
            }
        }
    }
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int a,b;
    cin>>a>>b;
    vector<int> fac;
    vector<int> count;
    vector<int> actual;
    init();
    int temp =a;
    
        for(int i=2;i<=a;i++){
            if(!sieve[i]&&temp%i==0){
                // cout<<"Try "<<i<<endl;
                fac.push_back(i);
                count.push_back(0);
                int tally = 0;
                while(temp%i==0){
                    tally++;
                    temp/=i;
                }
                actual.push_back(tally);
            }
        }
    
    // cout<<"done"<<endl;
    // for(int i=0;i<fac.size();i++){
    //     cout<<fac[i]<<endl;
    // }
    for(int i=2;i<=b;i++){
        // cout<<i<<endl;
        temp = i;
        for(int j=0;j<fac.size();j++){
            while(temp%fac[j]==0){
                count[j]++;
                temp/=fac[j];
            }
        }
    }
    // cout<<fac.size()<<actual.size()<<count.size()<<endl;
    int best = -1;
    for(int i=0;i<fac.size();i++){
        // cout<<fac[i]<<" "<<count[i]<<" "<<actual[i]<<endl;
        if(best==-1){
            best = count[i]/actual[i];
        }
        else{
            best = min(best, count[i]/actual[i]);
        }
    }
    cout<<best<<endl;
}