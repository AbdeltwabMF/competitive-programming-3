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

const int N = 1e2 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;
const double INF = 1e18, eps = 1e-9;

int Head[N], dis[N], Next[M], To[M], Cost[M], ne, n, m, u, v, e, t, tax;

void addEdge(int from, int to, int cost) {
    Next[++ne] = Head[from];
    Cost[ne] = cost;
    To[ne] = to;
    Head[from] = ne;
}

void Dijkstra(int src)
{
    memset(dis, 0x3f, sizeof(dis[0]) * (n + 2));
    priority_queue <pair <int, int> > Q;
    dis[src] = 0;
    Q.push({-dis[src], src});

    int node, cost;
    while(Q.size())
    {
        tie(cost, node) = Q.top(); Q.pop();
        if(-cost > dis[node]) continue;

        for(int i = Head[node]; i; i = Next[i]) if(dis[node] + Cost[i] < dis[To[i]]) {
            dis[To[i]] = dis[node] + Cost[i];
            Q.push({-dis[To[i]], To[i]});
        }
    }
}

void _clear()
{
    memset(Head, 0, sizeof(Head[0]) * (n + 2));
    ne = 0;
}

void Solve()
{
    _clear();
    cin >> n >> e >> t >> m;
    while(m--)
    {
        cin >> u >> v >> tax;
        addEdge(v, u, tax); // Single Destination
    }

    Dijkstra(e);

    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans += (dis[i] <= t);

    cout << ans << endl;
}

int main()
{
    Fast();

    int tc = 1; cin >> tc;
    for(int i = 1; i <= tc; ++i)
    {
        if(i > 1) cout << endl;
        Solve();
    }
}
