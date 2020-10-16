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

int n, m, u, v, tax;
int dis[N][N];
unordered_map <int, int> cnt;

void Floyd_Warshall()
{
    for(int via = 1; via <= n; ++via)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(dis[i][via] + dis[via][j] < dis[i][j])
                    dis[i][j] = dis[i][via] + dis[via][j];
}

void Solve()
{
    int tc = 1; n = 100;
    while(cin >> u >> v && u && v)
    {
        memset(dis, 0x3f, sizeof dis);
        cnt.clear();
        for(int i = 1; i <= n; ++i) dis[i][i] = 0;

        dis[u][v] = 1;
        cnt[u] = 1;
        cnt[v] = 1;
        while(cin >> u >> v && u && v) dis[u][v] = cnt[u] = cnt[v] = 1;

        Floyd_Warshall();

        int ans = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j) if(dis[i][j] != oo)
                ans += dis[i][j];
                
        int pairs = (int)cnt.size() * ((int)cnt.size() - 1);
        cout << "Case " << tc++ << ": average length between pages = " << ans * 1.0 / pairs << " clicks" << endl;
    }
}

int main()
{
    Fast();

    cout << fixed << setprecision(3);

    int tc = 1;
    for(int i = 1; i <= tc; ++i) {
        Solve();
    }
}
