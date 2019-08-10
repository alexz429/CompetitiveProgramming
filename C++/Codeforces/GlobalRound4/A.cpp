#include <bits/stdc++.h>


using namespace std;
int main(){
    int parties;
    scanf("%d\n", &parties);
    int total=0;
    int start=-1;
    int coalition=0;
    queue<int> ans;
    for(int count=0;count<parties;count++){
        int next;
        scanf("%d", &next);
        total+=next;
        if(count==0){
            start=next;
            coalition+=next;
            ans.push(count+1);
        }
        else{
            if(next*2<=start){
                coalition+=next;
                ans.push(count+1);
            }
        }
    }
    if(coalition>(total/2)){
        printf("%d\n", ans.size());
        bool first=true;
        while(!ans.empty()){
            if(!first){
                printf(" ");
            }
            first=false;
            printf("%d", ans.front());
            ans.pop();
        }
        printf("\n");
        
    }
    else{
        printf("0\n");
    }
}