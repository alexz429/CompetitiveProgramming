#include <bits/stdc++.h>
using namespace std;
int main(){
    string in;
    cin>>in;
    int left=0;
    int right=0;
    for(int count=0;count<in.length();count++){
        if(in.at(count)=='0'){
            left++;
        }
        else{
            right++;
        }
    }
    printf("%d", min(left,right)*2);
}