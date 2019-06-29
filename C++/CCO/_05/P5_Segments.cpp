#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    int left = 0;
    int right = 0;
    bool r = false;
    bool l = true;
    int Lprev = 1;
    int Rprev = 1;
    for (int count = 0; count < N; count++)
    {
        int from, to, tempr = 1e9, templ = 1e9;
        bool tr = false, tl = false;
        scanf("%d %d", &from, &to);
        if(count==N-1){
            to=N;
        }
        if (l)
        {
            if (Lprev <= from)
            {
                tr = true;
                tempr = left + abs(Lprev - to);
            }
            else if (Lprev >= to)
            {
                tl = true;
                templ = left + abs(Lprev - from);
            }
            else
            {
                tl = true;
                tr = true;
                templ = left + abs(Lprev - to) * 2 + abs(Lprev - from);
                tempr = left + abs(Lprev - from) * 2 + abs(Lprev - to);
            }
        }
        if(r){
            if (Rprev <= from)
            {
                tr = true;
                tempr = min(tempr,right + abs(Rprev - to));
            }
            else if (Rprev >= to)
            {
                tl = true;
                templ = min(templ,right + abs(Rprev - from));
            }
            else
            {
                tl = true;
                tr = true;
                templ = min(templ,right + abs(Rprev - to) * 2 + abs(Rprev - from));
                tempr = min(tempr,right + abs(Rprev - from) * 2 + abs(Rprev - to));
            }
        }
        l=false, r=false;
        if(tl){
            l=true;
            left=templ;
        }
        if(tr){
            r=true;
            right=tempr;
        }
        // printf("%d %d %d %d %d %d\n", left, right, Lprev, Rprev, l,r);
        
        Lprev=from;
        Rprev=to;
    }
    right+=N-1;
    left+=N-1+abs(Lprev-N);
    if(l&&r){
        printf("%d\n", min(left,right));
    }
    else if(l){
        printf("%d\n", left);
    }
    else{
        printf("%d\n", right);
    }
}