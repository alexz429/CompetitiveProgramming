#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool occupy[200004];
bool other[200004];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int ppl;
    cin>>ppl;
    vector<int> loc;
    for(int i=0;i<ppl;i++){
        int next;
        cin>>next;
        loc.push_back(next);
        other[next]=true;
    }
    sort(loc.begin(), loc.end());
    for(int next:loc){
        if(!occupy[next-1]){
            occupy[next-1]=true;
        }
        else if(occupy[next]){
            occupy[next+1]=true;
        }
        else{
            occupy[next]=true;
        }
    }
    for(int i=0;i<=ppl+1;i++){
        if(other[i]){
            if(other[i+2]){
                other[i]=false;
                other[i+2]=false;
                other[i+1]=true;
                i+=2;
            }
            else if(other[i+1]){
                other[i]=false;
                i+=1;
            }
        }
    }
    int count2=0;
    for(int i=0;i<=ppl+1;i++){
        if(other[i])count2++;
    }
    cout<<count2<<" ";
    int count=0;
    for(int i=0;i<=ppl+1;i++){
        if(occupy[i])count++;
    }
    cout<<count<<endl;
    

}