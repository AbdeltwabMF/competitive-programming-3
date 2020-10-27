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

int Head[N], Next[M], To[M], Par[N], in_time[N], Low[N], ne, n, m, u, v, dfs_timer;
vector <pair <int, int> > bridges;

string line, why;
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
            Par[To[i]] = node;
            DFS(To[i]);
            Low[node] = min(Low[node], Low[To[i]]);

            if(Low[To[i]] > in_time[node])
                bridges.push_back({min(node, To[i]), max(node, To[i])});
        }
        else if(To[i] != Par[node])
            Low[node] = min(Low[node], in_time[To[i]]);
    }
}

void _clear() {
    memset(Head, 0,   sizeof(Head[0]) * (n + 2));
    memset(Par, -1,    sizeof(Par[0]) * (n + 2));
    memset(in_time, 0, sizeof(in_time[0]) * (n + 2));
    bridges.clear();
    dfs_timer = 0;
    ne = 0;
}

void Solve()
{
    _clear();
    cin.ignore();

    for(int i = 1; i <= n; ++i)
    {
        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> u >> why;

        while(ss >> v)
            addEdge(u, v);
    }

    for(int i = 0; i < n; ++i) if(in_time[i] == 0)
            DFS(i);

    sort(bridges.begin(), bridges.end());
    cout << bridges.size() << " critical links" << endl;

    for(pair <int, int> bridge : bridges)
        cout << bridge.first << " - " << bridge.second << endl;

    cout << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; cin >> n; ++i)
        Solve();
}

