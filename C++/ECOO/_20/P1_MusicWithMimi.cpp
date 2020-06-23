#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    map<string, int> chord;
    chord["C"]=0;
    chord["C#"]=1;
    chord["D"]=2;
    chord["D#"]=3;
    chord["E"]=4;
    chord["F"]=5;
    chord["F#"]=6;
    chord["G"]=7;
    chord["G#"]=8;
    chord["A"]=9;
    chord["A#"]=10;
    chord["B"]=11;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int index[4];
        for(int j=0;j<4;j++){
            string next;
            cin>>next;
            index[j] = chord[next];
        }
        int dist[3];
        dist[0] = (index[1]>index[0])?(index[1]-index[0]):(index[1]+12-index[0]);
        dist[1] = (index[2]>index[1])?(index[2]-index[1]):(index[2]+12-index[1]);
        dist[2] = (index[3]>index[2])?(index[3]-index[2]):(index[3]+12-index[2]);
        // cout<<dist[0]<<" "<<dist[1]<<" "<<dist[2]<<endl;
        if(dist[0]==4&&dist[1]==3&&dist[2]==3){
            cout<<"root"<<endl;
        }
        else if(dist[0]==3&&dist[1]==3&&dist[2]==2){
            cout<<"first"<<endl;
        }
        else if(dist[0]==3&&dist[1]==2&&dist[2]==4){
            cout<<"second"<<endl;
        }
        else if(dist[0]==2&&dist[1]==4&&dist[2]==3){
            cout<<"third"<<endl;
        }
        else{
            cout<<"invalid"<<endl;
        }
        
    }

}