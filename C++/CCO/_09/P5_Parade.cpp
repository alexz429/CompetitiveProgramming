#include <bits/stdc++.h>
using namespace std;

void genMap(int* target, int x,int y,int k ){
    for(int count=0;count<16;count++){
        target[count]=count;
    }
    int prev=-1;
    x--;
    y--;
    int start=x*4+y;
    for(int count=1;count<k;count++){
        target[start+count]=start+count-1;
        target[start+k-1+4*count]=start+k-1+4*(count-1);
        target[start+k-1-count+4*(k-1)]=start+k-count+4*(k-1);
        target[start+4*(k-1-count)]=start+4*(k-count);
    }
}
void output(int* source){
    for(int count=0;count<16;count++){
        printf("%d", source[count]+1);

        if((count+1)%4==0){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
}
void merge(int* store,int* left, int *right){
    // printf("TRYING\n");
    // output(left);
    // output(right);
    for(int count=0;count<16;count++){
        // printf("COUNT: %d %d %d\n", count, left[count], right[count]);
        store[count]=left[right[count]];
    }
}

int** input;
int** segTree;
void build(int** target, int l, int r, int index){
    // printf("%d %d", l, r);
    if(l==r){
        target[index]=input[r];
        // output(target[index]);
        return;
    }
    target[index]=new int[16];
    int mid=(l+r)/2;
    build(target, l,mid,index*2);
    // output(target[index*2]);
    build(target, mid+1,r,index*2+1);
    // printf("done children");
    merge(target[index], target[index*2], target[index*2+1]);
    // printf("moving up");
}
void change(int** target, int l, int r, int index,int aim, int x, int y, int k){
    if(l==r&&r==aim){
        genMap(target[index], x,y,k);
        return;
    }
    int mid=(l+r)/2;
    if(aim<=mid){
        change(target, l,mid,index*2,aim,x,y,k);
    }
    else{
        change(target,mid+1,r,index*2+1,aim,x,y,k);
    }
    merge(target[index], target[index*2], target[index*2+1]);
}
int main(){
    int n,q;
    scanf("%d %d", &n,&q);
    input=new int*[n];
    for(int count=0;count<n;count++){
        input[count]=new int[16];
    }
    int max=0;
    int cur=1;
    for(int count=0;count<30;count++){
        if((cur&n)!=0){
            max=count+1;
        }
        cur<<=1;
    }
    max++;
    cur=1<<max;
    segTree=new int*[cur];
    for(int count=0;count<n;count++){
        int x,y,k;
        scanf("%d %d %d", &x,&y,&k);
        genMap(input[count], x,y,k);
        // output(input[count]);
    }

    build(segTree,0,n-1,1);
    // output(segTree[1]);
    for(int count=0;count<q;count++){
        int index, x,y,k;
        scanf("%d %d %d %d", &index, &x,&y,&k);
        index--;
        change(segTree,0,n-1,1,index,x,y,k);
        output(segTree[1]);
    }

}