#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define endl    '\n'

using namespace std;

typedef int64_t  ll;

void Fast() {
    cin.sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

const int dr []     = {-1, 0, 1, 0};
const int dc []     = {0, 1, 0, -1};
const char dir []   = {'U', 'R', 'D', 'L'};
map <char, int> inv = { {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

const int N = 1e2 + 9, M = 2e5 + 9, oo = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n;

int calc(int i, int j, int k, int l, int m)
{
    i *= 10;
    i += j;
    i *= 10;
    i += k;
    i *= 10;
    i += l;
    i *= 10;
    i += m;

    return i;
}

void Solve()
{
    int flag = true;

    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            for(int k = 0; k < 10; ++k)
                for(int l = 0; l < 10; ++l)
                    for(int m = 0; m < 10; ++m) {

                        int res = calc(i, j, k, l, m);
                        int abc = res * n;

                        if(abc > 98765 || res < 1234) continue;

                        int used = res < 10000;

                        int tmp = res;
                        while(tmp) used |= (1 << (tmp % 10)), tmp /= 10;

                        tmp = abc;
                        while(tmp) used |= (1 << (tmp % 10)), tmp /= 10;

                        if(used == (1 << 10) - 1)
                            cout << abc << " / " << (res < 10000 ? "0" : "") << res << " = " << n << endl, flag = false;
                    }
    if(flag)
        cout << "There are no solutions for " << n << "." << endl;
}

int main()
{
    Fast();

    int tc = 1;
    for(int i = 1; cin >> n && n; ++i) {
        if(i > 1) cout << endl;
        Solve();
    }
}

