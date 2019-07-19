#include <bits/stdc++.h>
using namespace std;

bool isSub(string a, string b){
    int at=0;
    for(int count=0;count<a.length();count++){
        if(at>=b.length())return false;
        while(b.at(at)!=a.at(count)){
            at++;
            if(at>=b.length())return false;
        }
        at++;
    }
    return true;
}

        int tallies[26];
        int comp[26];
int main(){
    int limit;
    cin>>limit;

    for(int count=0;count<limit;count++){
        fill(&tallies[0], &tallies[26], 0);
        fill(&comp[0], &comp[26], 0);
        string init,target,has;
        cin>>init>>target>>has;
        if(!isSub(init,target)){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<init.length();i++){
            tallies[init.at(i)-97]++;
        }
        for(int i=0;i<target.length();i++){
            comp[target.at(i)-97]++;
        }
        
        for(int i=0;i<has.length();i++){
            tallies[has.at(i)-97]++;
        }
    
        bool wrong=false;
        for(int i=0;i<26;i++){
            // printf("%d %d\n", comp[i], tallies[i]);
            if(comp[i]>tallies[i]){
                cout<<"NO"<<endl;
                wrong=true;
                break;
            }
        }
        if(wrong)continue;
        cout<<"YES"<<endl;
    }
    
}