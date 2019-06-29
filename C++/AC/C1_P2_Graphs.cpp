#include <bits/stdc++.h>
using namespace std;
vector<int> *direct;
int *parents;
bool *hit1;
bool *hit2;
int findParent(int a)
{
    if (parents[a] == a)
        return a;
    parents[a] = findParent(parents[a]);
    return parents[a];
}
void merge(int a, int b)
{
    if ((a = findParent(a)) == (b = findParent(b)))
    {
        return;
    }
    parents[a] = parents[b];
}
bool connected(int a, int b)
{
    return findParent(a) == findParent(b);
}
int main()
{

    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    hit1 = new bool[n];
    hit2 = new bool[n];
    parents = new int[n];
    direct = new vector<int>[n];
    for (int count = 0; count < n; count++)
    {
        parents[count] = count;
    }
    for (int count = 0; count < m; count++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        from--;
        to--;
        direct[from].push_back(to);
        direct[to].push_back(from);
        merge(from, to);
    }
    for (int count = 0; count < q; count++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (connected(a, b))
        {
            fill(&hit1[0], &hit1[n], false);
            fill(&hit2[0], &hit2[n], false);
            queue<int> first;
            queue<int> second;
            int steps = 0;
            bool found = false;
            first.push(a);
            second.push(b);
            while (!(first.empty() && second.empty()))
            {
                int max = first.size();
                for (int i = 0; i < max; i++)
                {
                    int next = first.front();
                    first.pop();
                    if (hit1[next])
                        continue;
                    if (hit2[next])
                    {
                        found = true;
                        printf("%d\n", steps * 2 - 1);
                        break;
                    }
                    hit1[next] = true;
                    for (int connect : direct[next])
                    {
                        first.push(connect);
                    }
                }
                if (found)
                    break;
                max = second.size();
                for (int i = 0; i < max; i++)
                {
                    int next = second.front();
                    second.pop();
                    if (hit2[next])
                        continue;
                    if (hit1[next])
                    {
                        found = true;
                        printf("%d\n", steps * 2);
                        break;
                    }
                    hit2[next] = true;
                    for (int connect : direct[next])
                    {
                        second.push(connect);
                    }
                }
                if (found)
                    break;
                steps++;
            }
        }
        else
        {
            printf("-1\n");
        }
    }
}
