#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct seg
{
    int size;
    int* arr;
};
struct seg* init(int size, int value){
int log = ceil(log2(size));
    struct seg* temp = (struct seg*) malloc(sizeof(struct seg));
    temp->arr = new int[(int)(2*pow(2,log))];
    fill(temp->arr[0], temp->arr[size], 0);
    temp-> size = size;
    return temp;
}
struct seg* init(vector<int> vals){//in progress
    struct seg* temp = init(vals.size(), 0);
    for(int i=0;i<vals.size();i++){
        changeVal(temp, vals[i], i);
    }
}
void changeValR(struct seg* st, int val, int index, int at, int l, int r){
    if(l == r){
        st->arr[at] = val;
        return;
    }
    int mid = (l+r)/2;
    if(index<=mid){
        st->arr[at]-=st->arr[at*2];
        changeValR(st, val, index, at*2, l, mid);
        st->arr[at]+=st->arr[at*2];
    }
    else{
        st->arr[at]-=st->arr[at*2+1];
        changeValR(st, val, index, at*2+1, mid+1, r);
        st->arr[at]+=st->arr[at*2+1];
    }
}
void changeVal(struct seg* st, int val, int index){
    changeValR(st, val, index, 1, 0,st->size);
}


int main(){
    struct seg* test = init(4, 0);
}