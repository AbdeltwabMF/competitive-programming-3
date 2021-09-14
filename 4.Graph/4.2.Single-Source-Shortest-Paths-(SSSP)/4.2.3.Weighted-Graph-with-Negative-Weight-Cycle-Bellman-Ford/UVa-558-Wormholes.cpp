#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl      '\n'

using namespace std;

typedef int64_t    ll;
typedef __int128 i128;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int N = 1e3 + 9, M = 2e6 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;
long double eps = 1e-9;

int Head[N], Par[N], Next[M], To[M], ne, n, m, u, v, st, tr, tax;
ll dis[N];
int Cost[M];

void addEdge(int from, int to, int cost) {
    Next[++ne] = Head[from];
    To[ne] = to;
    Cost[ne] = cost;
    Head[from] = ne;
}

vector <int> restorePath(int dest)
{
    vector <int> path;
    if(dis[dest] == INF) return path;

    for(int i = dest; ~i; i = Par[i])
        path.push_back(i);

    reverse(path.begin(), path.end());
    return path;
}

void _clear() {
    memset(Head, 0, sizeof Head);
    ne = 0;
}

bool hasNC()
{
    for(int i = 1; i <= n; ++i)
        for(int j = Head[i]; j; j = Next[j])
            if(dis[i] + Cost[j] < dis[To[j]])
                return true;

    return false;
}

bool Bellman_Ford(int src)
{
    memset(dis, 0x3f, sizeof dis);
    dis[src] = 0;

    bool newRelaxation = true;
    for(int k = 2; k <= n && newRelaxation; ++k)
    {
        newRelaxation = false;
        for(int i = 1; i <= n; ++i) {
            for(int j = Head[i]; j; j = Next[j]) if(dis[i] + Cost[j] < dis[To[j]]) {
                    dis[To[j]] = dis[i] + Cost[j];
                    newRelaxation = true;
                }
        }
    }
    return hasNC();
}

void Solve()
{
    _clear();

    cin >> n >> m;
    while(m--) {
        cin >> u >> v >> tax;
        u++, v++;
        addEdge(u, v, tax);
    }

    cout << ((Bellman_Ford(1)) ? "possible" : "not possible") << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

