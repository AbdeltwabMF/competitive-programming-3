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

void File() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 1e2 + 9, M = 1e4 + 9, oo = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll minusINF = 0xc0c0c0c0c0c0c0c0;

int Head[N], dis[N], enr[N], Next[M], To[M], Cost[M], ne, n, m, u, v, tax;

void addEdge(int from, int to, int cost) {
    Next[++ne] = Head[from];
    Cost[ne] = cost;
    To[ne] = to;
    Head[from] = ne;
}

bool Bellman_Ford(int src)
{
    memset(dis, 0, sizeof(dis[0]) * (n + 2));
    dis[src] = 100;

    bool newRelaxation = true;
    for(int k = 2; k <= n && newRelaxation; ++k)
    {
        newRelaxation = false;
        for(int i = 1; i <= n; ++i)
            for(int j = Head[i]; j; j = Next[j]) if(dis[i] > 0 && dis[i] + Cost[j] > dis[To[j]])
            {
                dis[To[j]] = dis[i] + Cost[j];
                newRelaxation = true;
            }
    }

    newRelaxation = true;
    for(int k = 2; k <= n && newRelaxation; ++k)
    {
        newRelaxation = false;
        for(int i = 1; i <= n; ++i)
            for(int j = Head[i]; j; j = Next[j]) if(dis[i] > 0 && dis[i] + Cost[j] > dis[To[j]])
            {
                dis[To[j]] = oo;
                newRelaxation = true;
            }
    }
    return true;
}

void _clear() {
    memset(Head, 0, sizeof(Head[0]) * (n + 2));
    ne = 0;
}

void Solve()
{
    _clear();

    for(int i = 1; i <= n; ++i) {
        cin >> enr[i] >> m;
        while(m--) {
            cin >> v;
            addEdge(i, v, 0);
        }
    }

    for(int i = 1; i <= n; ++i)
        for(int j = Head[i]; j; j = Next[j])
            Cost[j] = enr[To[j]];

    Bellman_Ford(1);

    if(dis[n] <= 0)
        cout << "hopeless" << endl;
    else
        cout << "winnable" << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; cin >> n && ~n; ++i)
        Solve();
}

