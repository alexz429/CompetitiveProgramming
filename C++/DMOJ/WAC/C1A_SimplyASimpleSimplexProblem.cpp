#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int count = 0; count < T; count++)
    {
        ll next;
        scanf("%lld", &next);
        
        ll next2=(ll)(sqrt(next*2)+1.5);
        while((next2-1)*(next2-2)/2>=next){
            next2--;
        }
        printf("%lld\n", next2);
        
    }
}
