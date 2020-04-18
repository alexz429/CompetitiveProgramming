#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int parents[5];

int findParent(int a){
    if(parents[a] == a)return a;
    return parents[a] = findParent(parents[a]);
}

bool isConnected(int a, int b){
    return findParent(a) == findParent(b);
}

void merge(int a, int b){
    parents[findParent(a)] = findParent(b);
}


int main(){

}