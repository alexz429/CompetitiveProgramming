#include <bits/stdc++.h>
using namespace std;
int limit;

    int maxNum;
    deque<int> output;
string* stuff[2];
bool recurse(int extent, string left, string right){
    if(extent!=0&&left.compare(right)==0){
        return true;
    }
    if(extent>=limit)return false;
    for(int count=0;count<maxNum;count++){
        output.push_back(count);
        if(recurse(extent+1, left+stuff[0][count], right+stuff[1][count]))return true;
        output.pop_back();
    }
    return false;
}

int main(){
    cin>>limit;
    cin>>maxNum;
    stuff[0]=new string[maxNum];
    stuff[1]=new string[maxNum];
    for(int count=0;count<maxNum;count++){
        cin>>stuff[0][count];
    }
    for(int count=0;count<maxNum;count++){
        cin>>stuff[1][count];
    }
    if(recurse(0,"","")){
        printf("%d\n", output.size());
        while(!output.empty()){
            printf("%d\n", output.front()+1);
            output.pop_front();
        }
    }
    else{
        printf("No solution.");
    }
}