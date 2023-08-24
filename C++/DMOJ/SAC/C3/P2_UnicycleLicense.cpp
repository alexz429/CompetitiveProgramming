#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double solve(double a, double b, double c) {
    double l = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    double r = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);

    if (l < 0) return r;
    if (r < 0) return l;
    return min(l, r);
}

int main() {
    int n;
    cin >> n;
    cout << setprecision(10) << solve(12, -5, 1 - n) << endl;
}