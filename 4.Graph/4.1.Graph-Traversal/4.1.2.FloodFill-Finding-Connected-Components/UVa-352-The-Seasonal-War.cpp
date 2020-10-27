#include "bits/stdc++.h"

using namespace std;

const int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
const char dir[] = {'D', 'U', 'R', 'L'};

void Fast() { cin.sync_with_stdio(0); cin.tie(0); cout.tie(0); }
void File()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif
}

/**----------------->>  Quality Over Quantity  <<----------------**/

int n, CCs;
char grid[30][30];

bool valid(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == '1';
}

void BFS(int sr, int sc)
{
    queue < array <int, 2> > Q;
    Q.push({sr, sc});
    grid[sr][sc] = 0;

    array <int, 2> cell;
    int r, c;

    while(Q.size())
    {
        cell = Q.front(); Q.pop();
        for(int i = 0; i < 8; ++i)
        {
            r = cell[0] + dx[i];
            c = cell[1] + dy[i];

            if(!valid(r, c)) continue;
            grid[r][c] = '0';
            Q.push({r, c});
        }
    }
}

void Solve()
{
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
        cin >> grid[i][j];

    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
        if(grid[i][j] == '1') BFS(i, j), ++CCs;
}

void MultiTest(bool Tests = 0)
{
    int tc = 1; (Tests) && (cin >> tc);
    for(int i = 1; cin >> n; ++i)
    {
        CCs = 0;
        Solve();
        cout << "Image number " << i << " contains " << CCs << " war eagles." << endl;
    }
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); File(); MultiTest();
}
