#include <bits/stdc++.h>
using namespace std;

int V,T,R1,R2,W;
int success[26][30][30];

string ans;
vector<pair<int,int>> convert[26];
unordered_set<int> has[26];
bool huh(int a, int l, int r){
    // printf("can %d fit %d - %d\n", a,l,r);
    if(success[a][l][r]!=-1){
        return success[a][l][r];
    }
    if(l==r){
        return success[a][l][r] = has[a].find(int(ans[r])-97)!=has[a].end();
    }
    for(pair<int,int> next:convert[a]){
        for(int i=l;i<r;i++){
            if(huh(next.first,l,i)&&huh(next.second,i+1,r)){
                return success[a][l][r]=1;
                
            }
        }
    }
    return success[a][l][r]=0;
}
int main(){
    cin>>V>>T;
    string buf;
    int start=0;
    getline(cin, buf);
    getline(cin, buf);
    // cout<<buf;
    start=int(buf[0])-65;
    getline(cin,buf);
    cin>>R1;
    getline(cin,buf);
    for(int count=0;count<R1;count++){
        
        getline(cin,buf);
        
        has[buf[0]-'A'].insert(buf[2]-'a');
    }
    cin>>R2;
    getline(cin,buf);
    for(int i=0;i<R2;i++){
        getline(cin,buf);
        convert[int(buf[0])-65].emplace_back(int(buf[2])-65,int(buf[4])-65);
    }
    cin>>W;
    getline(cin,buf);
    for(int i=0;i<W;i++){
        memset(success,-1,sizeof(success));
        cin>>ans;
        if(huh(start,0,ans.length()-1)){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
}