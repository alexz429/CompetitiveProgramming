#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> graph;
int shortest[200001];
int order[200001];

int main() {
    int n, w, d;
    cin >> n >> w >> d;
    for (int i = 0; i <= n; i++) {
        graph.push_back(vector<int>());
    }
    for (int i = 0; i < w; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;
        order[next] = i;
    }
    fill(shortest, shortest + 200000, -1);
    queue<int> bfs;
    bfs.push(n);
    int step = 0;
    while (!bfs.empty()) {
        int size = bfs.size();
        for (int i = 0; i < size; i++) {
            int next = bfs.front();
            bfs.pop();
            if (shortest[next] != -1) continue;
            shortest[next] = step;
            for (int nextNode : graph[next]) {
                bfs.push(nextNode);
            }
        }
        step++;
    }

    for (int i = 1; i <= n; i++) {
        cout << shortest[i] << endl;
    }
    int out = n;
    for (int i = 1; i <= n; i++) {
        if (shortest[i] == -1) continue;
        out = min(out, order[i] + shortest[i]);
    }
    for (int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;
        swap(order[x], order[y]);
        for (int i = 1; i <= n; i++) {
            cout << order[i] << endl;
        }
        if (shortest[x] != -1) out = min(out, order[x] + shortest[x]);
        if (shortest[y] != -1) out = min(out, order[y] + shortest[y]);
        cout << out << endl;
    }
}