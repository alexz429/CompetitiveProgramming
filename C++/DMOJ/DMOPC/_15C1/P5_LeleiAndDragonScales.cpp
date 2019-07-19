#include <bits/stdc++.h>
using namespace std;
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
        // printf("%d %d %d %d\n", x, y, x2, y2);
        return sums[x2][y2]-(y==0?0:sums[x2][y-1])-(x==0?0:sums[x-1][y2])+(x==0||y==0?0:sums[x-1][y-1]);
    }
};
int main(){
    int w,h,n;
    scanf("%d %d %d", &h,&w,&n);
    int** input=new int*[w];
    for(int count=0;count<w;count++){
        input[count]=new int[h];
    }
    for(int count=0;count<w;count++){
        for(int count2=0;count2<h;count2++){
            scanf("%intd", &input[count][count2]);
        }
    }
    PSum2<int> PSA(input,w,h);
    // printf("Finished Setup\n");
    int best=0;
    for(int count=0;count<w;count++){
        for(int count2=0;count2<h;count2++){
            // for(int i=count;i<w;i++){
            //     for(int j=count2;j<h;j++){
            //         if((i-count+1)*(j-count2+1)>n)continue;
            //         best=max(best,PSA.range(count,count2,i,j));
            //     }
            // }
            int height=-1;
            for(int count3=min(n-1,w-count);count3>=0;count3--){
                if(n/(count3+1)==height)continue;
                height=(n/(count3+1));
                best=max(best,PSA.range(count,count2,min(w-1,count+count3),min(h-1,count2-1+(n/(count3+1)))));
                // printf(" %d \n", best);
            }
        }
    }
    printf("%d\n", best);

}