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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll minusINF = 0xc0c0c0c0c0c0c0c0;

int Head[N], dis[N], frq[N], enr[N], Next[M], To[M], Cost[M], ne, n, m, u, v, tax;
bool in_queue[N];

void addEdge(int from, int to, int cost) {
    Next[++ne] = Head[from];
    Cost[ne] = cost;
    To[ne] = to;
    Head[from] = ne;
}

bool SPFA(int src)
{
    memset(in_queue, false, sizeof(in_queue[0]) * (n + 2));
    memset(dis, 0, sizeof(dis[0]) * (n + 2));
    memset(frq, 0, sizeof(frq[0]) * (n + 2));

    queue <int> Q;
    Q.push(src);
    dis[src] = 100;
    frq[src] = 1;
    in_queue[src] = true;

    int node;
    while(Q.size())
    {
        node = Q.front(); Q.pop(); in_queue[node] = false;
        for(int i = Head[node]; i; i = Next[i]) if(dis[node] + Cost[i] > dis[To[i]])
        {
            dis[To[i]] = dis[node] + Cost[i];
            if(!in_queue[To[i]])
            {
                if(++frq[To[i]] == n + n)
                    return true;
                if(frq[To[i]] == n)
                	dis[To[i]] = oo;
                Q.push(To[i]);
                in_queue[To[i]] = true;
            }
        }
    }
    return false;
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

    SPFA(1);

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

