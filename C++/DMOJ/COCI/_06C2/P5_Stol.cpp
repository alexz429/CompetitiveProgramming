#include <bits/stdc++.h>
template <typename T>struct PSum{
    T* sums;
    
    PSum(){
        
    }
    void create(T* input, int size){
        sums=new T[size];
        for(int count=0;count<size;count++){
            sums[count]=input[count]+(count==0?0:sums[count-1]);
        }
    }
    T range(int left, int right){
        return sums[right]-(left==0?0:sums[left-1]);
    }

};
int main(){
    int h,w;
    scanf("%d %d\n", &h, &w);
    PSum<int>* stuff=new PSum<int>[h];
    for(int count=0;count<h;count++){
        int* arr=new int[w];
        // printf("%d", count);
        for(int count2=0;count2<w;count2++){
            char val;
            scanf("%c", &val);
            if(val=='.'){
                arr[count2]=0;
            }
            else{
                arr[count2]=1;
            }
        }
        scanf("%*c");
        stuff[count].create(arr,w);
    }
    int best=0;
    for(int count=0;count<h;count++){
        for(int count2=0;count2<w;count2++){
            int width=w-1;
            int height=count;
            while(width>=count2&&height<h){
                if(stuff[height].range(count2,width)>0){
                    width--;
                }
                else{
                    best=std::max(best,2*(width-count2+1+height-count+1)-1);
                    // printf("%d %d %d %d\n", count2, width, count, height);
                    height++;
                }
            }
        }
    }
    printf("%d\n", best);
    

}