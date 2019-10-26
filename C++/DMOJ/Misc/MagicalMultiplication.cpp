#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    int temp = 0;
    for (int count = 0; count < a.length(); count++)
    {
        for (int count2 = 0; count2 < b.length(); count2++)
        {
            temp += (a[count] - '0') * (b[count2] - '0');
        }
    }
    cout << temp;
}