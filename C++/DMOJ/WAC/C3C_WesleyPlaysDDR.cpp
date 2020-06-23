#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<string,int>> combos;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string in;
    cin>>in;
    int max;
    cin>>max;
    for(int i=0;i<max;i++){
        string next;
        int score;
        cin>>next>>score;
        combos.push_back({next,score});
    }
    int curIndex= 0;
    int score = in.length();
    while(curIndex<in.length()-1){
        int highLength = 0;
        int nextScore = -1;
        for(pair<string,int> next: combos){
            if(next.first.length()>highLength){
                int endIndex = curIndex+next.first.length();
                if(endIndex>in.length()){
                    continue;
                }
                if(in.substr(curIndex, next.first.length()).compare(next.first) == 0){
                    nextScore = next.second;
                    highLength = next.first.length();
                }

            }
        }
        if(nextScore!=-1){

            // cout<<"lol "<<curIndex<<endl;
            score+=nextScore;
            curIndex+=highLength;
        }
        else{
            curIndex++;
        }
    }
    cout<<score<<"\n";
}