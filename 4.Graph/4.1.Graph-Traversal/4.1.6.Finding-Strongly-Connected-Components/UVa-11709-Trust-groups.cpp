#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl        '\n'
#define Min(a, b)   (((a) < (b)) ? (a) : (b));

using namespace std;

typedef int64_t  ll;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("input.in",  "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 1e5 + 9, M = 2e6 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[M], To[M], dfs_num[N], dfs_low[N], ne, n, m, tax, dfs_timer, component;
int Stack[N], top;
bool in_stack[N];
string u, v;
map <string, int> inv;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void _clear() {
    memset(Head,    0, sizeof(Head[0])    * (n + 2));
    memset(dfs_num, 0, sizeof(dfs_num[0]) * (n + 2));
    ne = dfs_timer = top = component = 0;
    inv.clear();
}

void Tarjan(int node)
{
    dfs_num[node] = dfs_low[node] = ++dfs_timer;
    in_stack[Stack[top++] = node] = true;

    for(int i = Head[node]; i; i = Next[i]) {
        if(dfs_num[To[i]] == 0)
            Tarjan(To[i]);

        if(in_stack[To[i]])
            dfs_low[node] = Min(dfs_low[node], dfs_low[To[i]]);
    }

    if(dfs_num[node] == dfs_low[node]) {
        ++component;
        for(int cur = -1; cur ^ node; in_stack[cur = Stack[--top]] = false) {}
    }
}

void Solve()
{
    _clear();

    cin.ignore();
    for(int i = 1; i <= n; ++i) {
        getline(cin, u);
        inv[u] = i;
    }

    while(m--) {
        getline(cin, u);
        getline(cin, v);
        addEdge(inv[u], inv[v]);
    }

    for(int i = 1; i <= n; ++i) if(!dfs_num[i])
            Tarjan(i);

    cout << component << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; (cin >> n >> m) && (n || m); ++i)
        Solve();
}

