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

const int N = 20 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll dis[N][N];
int n, m, u, v, q;

void Floyd_Warshall()
{
    for(int k = 1; k <= n; ++k)
        for(int u = 1; u <= n; ++u)
            for(int v = 1; v <= n; ++v)
                if(dis[u][k] + dis[k][v] < dis[u][v])
                    dis[u][v] = dis[u][k] + dis[k][v];
}

void Solve()
{
    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= n; ++i) dis[i][i] = 0;

    for(int i = 1; i <= 19; ++i) {
        if(i > 1) cin >> m;
        while(m--) {
            cin >> v;
            dis[v][i] = dis[i][v] = 1;
        }
    }

    n = 20;
    Floyd_Warshall();

    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        cin >> u >> v;
        if(u < 10) cout << " ";
        cout << u << " to ";
        if(v < 10) cout << " ";
        cout << v << ": " << dis[u][v] << endl;
    }
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; cin >> m; ++i) {
        cout << "Test Set #" << i << endl;
        Solve();
        cout << endl;
    }
}
