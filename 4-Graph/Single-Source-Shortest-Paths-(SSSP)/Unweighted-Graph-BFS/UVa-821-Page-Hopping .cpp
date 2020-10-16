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

unordered_map <int, int> Head;
unordered_set <int> hs;
int Next[M], To[M], ne, n, m, u, v;
int dis[N];

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void BFS(int src)
{
    for(int i : hs) dis[i] = oo;
    queue <int> Q;
    dis[src] = 0;
    Q.push(src);

    int node;
    while(Q.size())
    {
        node = Q.front(); Q.pop();
        for(int i = Head[node]; i; i = Next[i]) if(dis[To[i]] == oo) {
            dis[To[i]] = dis[node] + 1;
            Q.push(To[i]);
        }
    }
}

void _clear()
{
    Head.clear();
    hs.clear();
    ne = 0;
}

void Solve()
{
    int tc = 1;
    while(cin >> u >> v && u && v)
    {
        _clear();

        addEdge(u, v);
        hs.insert(u); hs.insert(v);
        while(cin >> u >> v && u && v) {
            addEdge(u, v);
            hs.insert(u); hs.insert(v);
        }

        int ans = 0;
        for(int i : hs)
        {
            BFS(i);
            for(int j : hs) ans += dis[j];
        }

        int pairs = (int)hs.size() * ((int)hs.size() - 1);
        cout << "Case " << tc++ << ": average length between pages = " << ans * 1.0 / pairs << " clicks" << endl;
    }
}

int main()
{
    Fast();

    cout << fixed << setprecision(3);

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

