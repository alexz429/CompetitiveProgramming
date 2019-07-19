#include <bits/stdc++.h>
using namespace std;

bool **output;
int main()
{
    int max, com;
    scanf("%d %d", &max, &com);
    output = new bool *[max];
    for (int count = 0; count < max; count++)
    {
        output[count] = new bool[max];
        fill(&output[count][0], &output[count][max], false);
    }
    for (int count = 0; count < com; count++)
    {
        int x, y, w, h;
        scanf("%d %d %d %d", &x, &y, &w, &h);
        output[x][y] = !output[x][y];
        int x2 = x + w - 1;
        int y2 = y + h - 1;
        if (x2 < max - 1 && y2 < max - 1)
        {
            output[x2 + 1][y2 + 1] = !output[x2 + 1][y2 + 1];
        }
        if (x2 < max - 1)
        {
            output[x2 + 1][y] = !output[x2 + 1][y];
        }
        if (y2 < max - 1)
        {
            output[x][y2 + 1] = !output[x][y2 + 1];
        }
        for(int i=0;i<max;i++){
            for(int j=0;j<max;j++){
                // printf("%s ", output[i][j]?"true":"false");
            }
            // printf("\n");
        }
    }
    int tally=0;
    for (int count = 0; count < max; count++)
    {

        bool prev = false;
        for (int count2 = 0; count2 < max; count2++)
        {
            if (output[count][count2])
                prev = !prev;
            if(count!=0&&output[count-1][count2]){
                output[count][count2]=!prev;
            }
            else{
                output[count][count2]=prev;
            }
            if(output[count][count2])tally++;
        }
    }
    
    printf("%d", tally);
}