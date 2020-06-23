#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    deque<int> chain;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    chain.push_back(0);
    int tally = 1;
    int goal = a+b+c+1;
    int hydro = 0;
    while(tally!=goal){
        if(c>0&&chain.back()<2){
            hydro+=(4-chain.back()-3);
            chain.push_back(3);
            c--;
            tally++;
            continue;
        }
        else if(b>0&&chain.back()<3){
            hydro+=(4-chain.back()-2);
            chain.push_back(2);
            b--;
            tally++;
            continue;
        }
        else if(a>0&&chain.back()<4){
            hydro+=(4-chain.back()-1);
            chain.push_back(1);
            a--;
            tally++;
            continue;
        }
        cout<<"invalid"<<endl;
        return 0;
    }
    hydro += (4-chain.back());
    if(hydro==d){
        cout<<"C"<<goal<<"H"<<hydro<<endl;
    }
    else{  
        cout<<"invalid"<<endl;
    }
}