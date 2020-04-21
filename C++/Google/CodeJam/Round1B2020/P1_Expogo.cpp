#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int tally = 1;
void solve(int a, int b)
{
    cout << "Case #" << tally++ << ": ";
    bool one = a > 0;
    bool two = b > 0;
    a = abs(a);
    b = abs(b);
    if((a&1)==(b&1)){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    string out = "";
    bool prevFlip = false;
    while (a != 0 || b != 0)
    {
        // cout<<a<<" "<<b<<endl;
        //check for evens while either side hasn't seen a 0
        int check = 0;
        int comp = 1;
        if ((a & 1) == 1)
        {
            if ((a > 1 || b > 1) && (a & 2) == (b & 2))
            {
                out += (one) ? "W" : "E";
                a++;
            }
            else
            {
                out += (one) ? "E" : "W";
                a--;
            }
        }
        else if ((b & 1) == 1)
        {
            if ((a > 1 || b > 1) && (a & 2) == (b & 2))
            {
                out += (two) ? "S" : "N";
                b++;
            }
            else
            {

                out += (two) ? "N" : "S";
                b--;
            }
        }
        a >>= 1;
        b >>= 1;
    }
    cout << out << endl;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int t = 0; t < n; t++)
    {
        ll a, b;
        cin >> a >> b;
        solve(a, b);
    }
}