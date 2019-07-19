#include <bits/stdc++.h>

template <typename T>struct PSum{
    T* sums;
    PSum(T* input, int size){
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
    int max;
    scanf("%d", &max);
    int* stuff=new int[max];
    for(int count=0;count<max;count++){
        scanf("%d",&stuff[count]);
    }
    PSum<int> test(stuff,max);
    printf("%d\n", test.range(2,5));
}