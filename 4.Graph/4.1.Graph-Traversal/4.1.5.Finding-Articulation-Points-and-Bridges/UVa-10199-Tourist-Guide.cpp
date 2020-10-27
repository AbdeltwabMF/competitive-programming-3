#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define endl    '\n'
#define UNVISITED 0
#define EXPLORED  1
#define VISITED   2

using namespace std;

typedef int64_t  ll;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

void File() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
}

const int N = 1e5 + 9, M = 1e6 + 9, oo = 0x3f3f3f3f;
ll INF = 0x3f3f3f3f3f3f3f3f;

int Head[N], Next[M], To[M], Par[N], in_time[N], Low[N], ne, n, m, dfs_timer;

int root, rootChildren;
bool Art[N];

vector <pair <int, int> > bridges;
map <string, int> inv;

string line, why, u, v, ar[N];
stringstream ss;

void addEdge(int from, int to) {
    Next[++ne] = Head[from];
    Head[from] = ne;
    To[ne] = to;
}

void DFS(int node)
{
    in_time[node] = Low[node] = ++dfs_timer;

    for(int i = Head[node]; i; i = Next[i])
    {
        if(in_time[To[i]] == 0)
        {
            if(node == root) rootChildren++;
            Par[To[i]] = node;
            DFS(To[i]);
            Low[node] = min(Low[node], Low[To[i]]);

            if(Low[To[i]] >= in_time[node])
                Art[node] = true;
        }
        else if(To[i] != Par[node])
            Low[node] = min(Low[node], in_time[To[i]]);
    }
}

void _clear() {
    memset(Head, 0,   sizeof(Head[0]) * (n + 2));
    memset(Par, -1,    sizeof(Par[0]) * (n + 2));
    memset(Art, false, sizeof(Art[0]) * (n + 2));
    memset(in_time, 0, sizeof(in_time[0]) * (n + 2));
    bridges.clear();
    inv.clear();
    dfs_timer = 0;
    ne = 0;
}

void Solve()
{
    _clear();

    for(int i = 1; i <= n; ++i)
    {
        cin >> ar[i];
        inv[ar[i]] = i;
    }

    cin >> m;
    while(m--)
    {
        cin >> u >> v;
        addEdge(inv[u], inv[v]);
        addEdge(inv[v], inv[u]);
    }

    for(int i = 1; i <= n; ++i) if(in_time[i] == 0)
    {
        root = i;
        rootChildren = 0;
        DFS(i);
        Art[i] = rootChildren > 1;
    }

    vector <string> Arti;
    for(int i = 1; i <= n; ++i) if(Art[i])
        Arti.push_back(ar[i]);

    sort(Arti.begin(), Arti.end());

    cout << Arti.size() << " camera(s) found" << endl;

    for(string s : Arti)
        cout << s << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; cin >> n && n; ++i)
    {
        if(i > 1) cout << endl;
        cout << "City map #" << i << ": ";
        Solve();
    }
}

