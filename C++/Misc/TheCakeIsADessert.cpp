#include <bits/stdc++.h>

using namespace std;
#define ll long long
template<typename T> struct DiffArray2{
    T** out;
    T** OG;
    int w;
    int h;
    T clamp;
    DiffArray2(T** input, int hori, int verti, T mod){
        OG=input;
        w=hori;
        h=verti;
        clamp=mod;
        out=new T*[hori];
        for(int count=0;count<hori;count++){
            out[count]=new T[verti];
            std::fill(&out[count][0], &out[count][verti], 0);
        }
    }
    void add(int x, int y, int x2, int y2, T change){
        out[x][y]+=change;
        out[x][y]%=clamp;
        if(x2<w-1&&y2<h-1){
            out[x2+1][y2+1]+=change;
            out[x2+1][y2+1]%=clamp;
        }
        if(x2<w-1){
            out[x2+1][y]-=change;
            out[x2+1][y]%=clamp;
        }
        if(y2<h-1){
            out[x][y2+1]-=change;
            out[x][y2+1]%=clamp;
        }
    }
    T** output(){
        for (int count = 0; count < w; count++)
    {

        int prev = 0;
        for (int count2 = 0; count2 < h; count2++)
        {
            // printf("%d ",out[count][count2]);
            prev+=out[count][count2];
            if(count!=0&&out[count-1][count2]){
                out[count][count2]=out[count-1][count2]+prev;
            }
            else{
                out[count][count2]=prev;
            }
        }
        // printf("\n");
    }
        return out;
    }
};
template<typename T> struct PSum2{
    T** sums;
    PSum2(T** input, int hori, int verti){
        sums=new T*[hori];
        for(int count=0;count<hori;count++){
            sums[count]=new T[verti];
            for(int count2=0;count2<verti;count2++){
                sums[count][count2]=input[count][count2]+(count==0?0:sums[count-1][count2])+(count2==0?0:sums[count][count2-1])-(count2==0||count==0?0:sums[count-1][count2-1]);
                // printf("%d ",sums[count][count2]);
            }
            // printf("\n");
        }
    }
    T range(int x, int y, int x2, int y2){
        return sums[x2][y2]-(y==0?0:sums[x2][y-1])-(x==0?0:sums[x-1][y2])+(x==0||y==0?0:sums[x-1][y-1]);
    }
};
int main(){
int n,m,k;
scanf("%d %d %d", &n,&m,&k);
ll** base=new ll*[n];
for(int count=0;count<n;count++){
base[count]=new ll[m];
}
DiffArray2<ll> first(base,n,m,2000000);
for(int count=0;count<k;count++){
    int x,y,x2,y2;
    scanf("%d %d %d %d", &x,&y,&x2,&y2);
    x--,y--,x2--,y2--;
    first.add(x,y,x2,y2,1);
}
base=first.output();
PSum2<ll> second(base,n,m);
int q;
scanf("%d", &q);
for(int count=0;count<q;count++){
    int x,y,x2,y2;
    scanf("%d %d %d %d", &x,&y,&x2,&y2);
    x--,y--,x2--,y2--;
    printf("%lld\n", second.range(x,y,x2,y2));
}
}