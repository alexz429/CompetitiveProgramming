#include <bits/stdc++.h>

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
            printf("%d ",out[count][count2]);
            prev+=out[count][count2];
            if(count!=0&&out[count-1][count2]){
                out[count][count2]=out[count-1][count2]+prev;
            }
            else{
                out[count][count2]=prev;
            }
        }
        printf("\n");
    }
        return out;
    }
};
int main(){
    int max;
    scanf("%d", &max);
    int** base=new int*[max];
    for(int count=0;count<max;count++){
        base[count]=new int[max];
        std::fill(&base[count][0], &base[count][max],0);
    }
    DiffArray2<int> output(base,max,max, 10);
    int times;
    scanf("%d", &times);
    for(int count=0;count<times;count++){
        int x,y,x2,y2;
        scanf("%d %d %d %d", &x,&y,&x2,&y2);
        output.add(x,y,x2,y2,1);
    }
    base=output.output();
    for(int count=0;count<max;count++){
        for(int count2=0;count2<max;count2++){
            // printf("%d ", base[count][count2]);
            printf("%d ", base[count][count2]);
            // printf("hi");
        }
        printf("\n");
        // printf("\n");
    }
}