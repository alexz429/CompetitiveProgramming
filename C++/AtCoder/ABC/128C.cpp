#include <iostream>
#include <bits/stdc++.h>


int main(){
    int bulbs, switches;
    scanf("%d %d", &switches, &bulbs);
    int **bulbSet=new int*[bulbs];
    int *sizes=new int[bulbs];
    for(int count=0;count<bulbs;count++){
        int max;
        scanf("%d", &max);
        bulbSet[count]=new int[max];
        sizes[count]=max;
        for(int count2=0;count2<max;count2++){
            int next;
            scanf("%d", &next);
            bulbSet[count][count2]=next;
            bulbSet[count][count2]--;
        }
    }
    
    int *keys=new int[bulbs];
    for(int count=0;count<bulbs;count++){
        scanf("%d", &keys[count]);
    }
    int tally=0;
    for(int count=0;count<(1<<(switches));count++){
      
        bool good=true;
        for(int count2=0;count2<bulbs;count2++){
            int number=0;
            // printf("%d\n", sizes[count2]);
            for(int count3=0;count3<sizes[count2];count3++){
                // printf("tally\n");
                int comp=count&(1<<(bulbSet[count2][count3]));
                // printf("%d %d\n", count3, comp);
                if(comp!=0){
                    // printf("%d",comp);
                    number++;
                }
            }
            // printf("keys %d", number);
            if(number%2!=keys[count2]){
                good=false;
                break;
            }
            // printf("Pass %d\n", count2);
        }
        if(good){
//   printf("%d\n", count);
            tally++;
        }
    }
    printf("%d", tally);
    for(int count=0;count<bulbs;count++){
        delete[] bulbSet[count];
    }
    delete[] keys;
}
