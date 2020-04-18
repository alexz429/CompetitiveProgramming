#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tally[3];
int psa[1000000][3];
int* yikes[3];
int* psa_q(int l,int r){
    if(l>r){
        int* o = new int[3];
        o[0]=0;
        o[1]=0;
        o[2]=0;
    }
    
    int* lmao = new int[3];
    if(l==0){
        
    for(int i=0;i<3;i++){
        lmao[i] = psa[r][i];
    }
    return lmao;
    }
    l--;
    for(int i=0;i<3;i++){
        lmao[i] = psa[r][i] - psa[l][i];
    }
    return lmao;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string in;
    cin>>in;
    for(int i=0;i<in.length();i++){
        tally[in[i]-'A']++;
        for(int j=0;j<3;j++){
            psa[i][j] = tally[j];
        }
    }
    
    // for(int i=0;i<in.length();i++){
    //     cout<<psa[i][0]<<" ";
    // }
    // cout<<endl;
    ll best = -1;
    for(int i=0;i<3;i++){
        for(int j=0;j<tally[i];j++){
            for(int k=0;k<3;k++){
                if(k==i)continue;
                int rem = -1;
                for(int l=0;l<3;l++){
                    if(l!=k&&l!=i){
                        rem = l;
                        break;
                    }
                }
                int breaks[3];
                breaks[0] = j;
                breaks[1] = j+tally[k];
                breaks[2] = breaks[1]+tally[rem];
                // cout<<tally<<" ";
                yikes[0] = psa_q(0,j);
                
                yikes[1]=psa_q(breaks[0]+1, breaks[1]);
                yikes[2]=psa_q(breaks[1]+1, breaks[2]);
                ll comp = 0;
                // cout<<tally<<" ";
                // cout<<tally<<" ";
                if(breaks[2]!=in.length()-1){
                    int* add = psa_q(breaks[2]+1, in.length()-1);
                    for(int count=0;count<3;count++){
                        yikes[0][count]+=add[count];
                    }
                }
                comp+=yikes[0][rem];
                comp+=yikes[1][rem];
                if(yikes[0][rem]>=yikes[2][i]){
                    yikes[0][k]+=yikes[0][rem]-yikes[2][i];
                    comp+=yikes[0][k];
                }
                else{
                    yikes[1][i]+=yikes[1][rem]-yikes[2][k];
                    comp+=yikes[1][i];
                }
                // for(int i=0;i<3;i++){
                //     cout<<breaks[i]<<" ";
                // }
                // cout<<i<<" "<<k<<" "<<rem<<" "<<comp<<endl;
                if(best==-1)best = comp;
                best = min(best, comp);
            }
        }
    }
    cout<<best<<endl;
}