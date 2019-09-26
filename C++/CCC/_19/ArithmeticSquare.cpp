#include <bits/stdc++.h> 
typedef long long ll;
using namespace std;
int blank=0;
int grid[3][3];
bool go = true;
void fillR(){
    for(int i=0;i<3;i++){
        int count=0;
        for(int j=0;j<3;j++){
            if(grid[i][j]!=1000001){
                count++;
            }
        }
        if(count==2){
            if(grid[i][0]==1000001){
                grid[i][0] = grid[i][1] - (grid[i][2]- grid[i][1]);
            }
            else if(grid[i][1]==1000001){
                grid[i][1] = (grid[i][0]+grid[i][2])/2;
            }
            else if(grid[i][2]==1000001){
                grid[i][2] = (grid[i][1])+ (grid[i][1]- grid[i][0]);
            }
            go = true;
            blank--;
        }
    }
}
void fillC(){
    for(int i=0;i<3;i++){
        int count=0;
        for(int j=0;j<3;j++){
            if(grid[j][i]!=1000001){
                count++;
            }
        }
        if(count==2){
            if(grid[0][i]==1000001){
                grid[0][i] = grid[1][i] - (grid[2][i]- grid[1][i]);
            }
            else if(grid[1][i]==1000001){
                grid[1][i] = (grid[0][i]+grid[2][i])/2;
            }
            else if(grid[2][i]==1000001){
                grid[2][i] = (grid[1][i])+ (grid[1][i]- grid[0][i]);
            }
            go = true;
            blank--;
        }
    }
}
void solve(){
    go = true;
    while(go){
        go = false;
        fillC();
        fillR();
    }
}
bool oppo(){
    blank--;
    if(grid[0][1]==1000001){
        if(grid[2][1]!=1000001){
            grid[0][1]=grid[2][1];
            return true;
        }
    }
    else if(grid[1][0]==1000001){
        if(grid[1][2]!=1000001){
            grid[1][0]=grid[1][2];
            return true;
        }
    }
    else if(grid[1][2]==1000001){
        if(grid[1][0]!=1000001){
            grid[1][2]=grid[1][0];
            return true;
        }
    }
    else if(grid[2][1]==1000001){
        if(grid[0][1]!=1000001){
            grid[2][1]=grid[0][1];
            return true;
        }
    }
    blank++;
    return false;
}
int getPari(){
    if(grid[0][0]!=1000001){
        return grid[0][0];
    }
    if(grid[0][2]!=1000001){
        return grid[0][2];
    }
    if(grid[2][0]!=1000001){
        return grid[2][0];
    }
    if(grid[2][2]!=1000001){
        return grid[2][2];
    }
    return 0;
}
bool checkPari(){
    int pari = -1;
    if(grid[0][0]!=1000001){
        pari = grid[0][0]%2;
    }
    if(grid[0][2]!=1000001){
        if(pari==-1){
            pari = grid[0][2]%2;
        }
        else if((grid[0][2]-pari)%2!=0){
            return false;
        }
    }
    if(grid[2][2]!=1000001){
        if(pari==-1){
            pari = grid[2][2]%2;
        }
        else if((grid[2][2]-pari)%2!=0){
            return false;
        }
    }
    if(grid[2][0]!=1000001){
        if(pari==-1){
            pari = grid[2][0]%2;
        }
        else if((grid[2][0]-pari)%2!=0){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int count=0;count<3;count++){
        for(int i=0;i<3;i++){
            string next;
            cin>> next;
            if(!next.compare("X")){
                blank++;
                grid[count][i]=1000001;
            }
            else{
                grid[count][i]=stoi(next);
            }
        }

    }   
    solve();
    while(blank!=0){
    //     for(int i = 0 ; i<3;i++){
    //     for(int j=0;j<3;j++){
    //         printf("%d",grid[i][j]);
    //         if(j!=2){
    //             printf(" ");
    //         }
    //     }
    //     printf("\n");
    // }
        if(oppo()){
            solve();
            continue;
        }

        int next = getPari();
        if(grid[0][0]==1000001){
            blank--;
            grid[0][0] = next;
        }
        else if(grid[0][2]==1000001){
            blank--;
            grid[0][2]=next;
        }
        else if(grid[2][2]==1000001){
            blank--;
            grid[2][2]=next;
        }
        else if(grid[2][0]==1000001){
            blank--;
            grid[2][0]=next;    
        }
        
        
        solve();
    }
    for(int i = 0 ; i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d",grid[i][j]);
            if(j!=2){
                printf(" ");
            }
        }
        printf("\n");
    }

}