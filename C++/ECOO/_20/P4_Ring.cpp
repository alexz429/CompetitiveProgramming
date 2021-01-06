#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MN = 1e5+5, BASE = 31, MOD = 1e9+7, ITERS = 100, ADD = 1e5;
map<string,int> name;
pll fun[MN];
void solve() {
    int n,curfun=-1,id=0; ll x = 0;
    cin >> n; string s; stack<int> funs; funs.push(-1);
    while (n--) {
        cin >> s;
        if (s == "END") {
            funs.pop(); curfun = funs.top();
        } else if (s == "FUN") {
            string wot; cin >> wot; name[wot]=++id; funs.push(id); curfun = id; fun[id]={1,0};
        } else if (s == "CALL") {
            string wot; cin >> wot; int call = name[wot];
            if (curfun == -1) x = (x * fun[call].first % MOD + fun[call].second) % MOD;
            else fun[curfun].first = (fun[curfun].first * fun[call].first) % MOD, fun[curfun].second = (fun[curfun].second * fun[call].first % MOD + fun[call].second) % MOD;
        } else if (s == "ADD") {
            ll v; cin >> v;
            if (curfun == -1) x = (x + v) % MOD;
            else fun[curfun].second = (fun[curfun].second + v) % MOD;
        } else if (s == "SUB") {
            ll v; cin >> v;
            if (curfun == -1) x = ((x - v)%MOD + MOD) % MOD;
            else fun[curfun].second = ((fun[curfun].second-v)%MOD+MOD)%MOD;
        } else {
            ll v; cin >> v;
            if (curfun == -1) x = (x * v) % MOD;
            else fun[curfun].first = (fun[curfun].first * v) % MOD, fun[curfun].second = (fun[curfun].second * v) %MOD;
        }
    }
    cout << x << endl;
    name.clear();
    for (int i = 0; i <= id; i++) fun[i] = {0,0};
}
int main () { //kill me
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}