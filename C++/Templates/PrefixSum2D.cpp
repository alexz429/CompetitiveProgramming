#include <bits/stdc++.h>

template<typename T> struct PSum2{
    T** sums;
    PSum2(T** input, int hori, int verti){
        sums=new T*[hori];
        for(int count=0;count<hori;count++){
            sums[count]=new T[verti];
            for(int count2=0;count2<verti;count2++){
                sums[count][count2]=input[count][count2]+(count==0?0:sums[count-1][count2])+(count2==0?0:sums[count][count2-1])-(count2==0||count==0?0:sums[count-1][count2-1]);
                printf("%d ",sums[count][count2]);
            }
            printf("\n");
        }
    }
    T range(int x, int y, int x2, int y2){
        return sums[x2][y2]-(y==0?0:sums[x2][y-1])-(x==0?0:sums[x-1][y2])+(x==0||y==0?0:sums[x-1][y-1]);
    }
};
int main(){
    int w,h;
    scanf("%d %d", &w, &h);
    int** input=new int*[w];
    for(int count=0;count<w;count++){
        input[count]=new int[h];
        for(int count2=0;count2<h;count2++){
            scanf("%d", &input[count][count2]);
        }
    }
    PSum2<int> test(input,w,h);
    printf("%d", test.range(1,1,3,4));
}