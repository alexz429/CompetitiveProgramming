#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n,k;
    scanf("%d %d\n", &n,&k);
    ll* psa=new ll[n];
    for(int count=0;count<n;count++){
        ll next;
        scanf("%lld", &next);
        psa[count]=(count==0)?next:next+psa[count-1];
        // printf("%lld\n", psa[count]);
    }
    bool start=false;
    deque<ll> smol;
    ll best=0;
    for(int count=0;count<n+k-1;count++){
        if(count==k-1){
            start=true;
        }
        if(count==n){
            deque<ll> copy;
            for(int count2=n-k+1;count2<n;count2++){
                ll nextComp;
                nextComp=psa[count2-1];
                while(!copy.empty()&&copy.back()>(psa[n-1]-nextComp)*-1){
                    copy.pop_back();
                }
                copy.push_back((psa[n-1]-nextComp)*-1);
            }
            smol=copy;
        }
        while(!smol.empty()&&smol.back()>psa[count%n]){
            smol.pop_back();
        }
        smol.push_back(psa[count%n]);
        if(start){
            if(count>=k){
                ll compare=(count>=n)?(psa[n-1]-psa[count-k])*-1:psa[count-k];
                if(smol.front()==compare){
                    smol.pop_front();
                }
            }
            ll next=psa[count%n]-smol.front();
            if(count>=n){
                next=max(next,psa[count%n]+psa[n-1]-psa[count-k]);
            }
            else{
                next=max(next,psa[count]-((count-k>=0)?psa[count-k]:0));
            }
            // printf("%lld %lld\n",smol.front(), next);
            best=max(next,best);
        }
    }
    printf("%lld\n", best);

}