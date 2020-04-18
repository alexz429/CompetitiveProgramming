#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SENTINEL 27644437
#define SENTINEL2 27072719
int arr[26];
int comp[26];
bool stuff[SENTINEL];
bool stuff2[SENTINEL2];
int power[200004];
int power2[200004];

int lift(int in, char a, int length){
    int start = a-'a';
    start = (start*(power[length]))%SENTINEL;
    in=(in-start+SENTINEL)%SENTINEL;
    return in;
}
int add(int in, char next){
    in=(in*26)%SENTINEL;
    in+=next-'a';
    return in;
}
int lift2(int in, char a, int length){
    int start = a-'a';
    start = (start*(power2[length]))%SENTINEL2;
    in=(in-start+SENTINEL2)%SENTINEL2;
    return in;
}
int add2(int in, char next){
    in=(in*26)%SENTINEL2;
    in+=next-'a';
    return in;
}
int main(){
    int start = 1;
    for(int i=0;i<200004;i++){
        power[i] = start;
        start = (start*26)%SENTINEL;
    }
    start = 1;
    for(int i=0;i<200004;i++){
        power2[i] = start;
        start = (start*26)%SENTINEL2;
    }
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    string a,b;
    cin>>a>>b;
    int cols = 0;
    int tally = 0;
    for(int i=0;i<a.length();i++){
        arr[a[i]-'a']++;
        if(arr[a[i]-'a']==1){
            cols++;
        }
    }
    // for(int i=0;i<26;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    int lmao = 0;
    int length = 0;
    int cur = 0;
    int cur2=0;
    for(int i=0;i<b.length();i++){
        
        int index = b[i]-'a';
        comp[index]++;
        // cout<<b.substr(i-length,length+1)<<endl;
        cur = add(cur, b[i]);
        cur2 = add2(cur2, b[i]);
        if(arr[index]<comp[index]){
            // cout<<"OOP"<<endl;
            // for(int i=0;i<26;i++){
            //     cout<<comp[i]<<" ";
            // }
            // cout<<endl;s
            for(;length>=0&&comp[index]>arr[index];length--){
                int index2=b[i-length]-'a';
                if(comp[index2]==arr[index2]){
                    lmao--;
                }
                comp[index2]--;
                cur = lift(cur, b[i-length], length);
                cur2 = lift2(cur2, b[i-length], length);
                
            }
            // for(int i=0;i<26;i++){
            //     cout<<comp[i]<<" ";
            // }
            // cout<<endl;
            // lmao++;
            // cout<<lmao<<endl;
            if(cols==lmao){
                // cout<<"GOT"<<endl;
                // cout<<b.substr(i-length, length+1)<<endl;
                if(!stuff[cur]||!stuff2[cur2]){
                stuff[cur]=true;
                stuff2[cur2]=true;
                tally++;
                }
            }
        }
        else {
            if(arr[index]==comp[index]){
                lmao++;
                if(lmao==cols){
                    // cout<<"GOT2"<<endl;
                // cout<<b.substr(i-length, length+1)<<endl;
                if(!stuff[cur]||!stuff2[cur2]){
                stuff[cur]=true;
                stuff2[cur2]=true;
                tally++;
                }
                }
            }
            // cout<<"LEN"<<length<<endl;
        }
        length++;
    }
    cout<<tally<<"\n";
}