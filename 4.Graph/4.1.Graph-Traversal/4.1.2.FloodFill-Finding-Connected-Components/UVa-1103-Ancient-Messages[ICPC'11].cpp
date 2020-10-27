#include "bits/stdc++.h"

#define  all(a)              (a).begin(), (a).end()
#define  sz(a)               (int)a.size()
#define  endl                '\n'

using namespace std;

int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void Fast() { cin.sync_with_stdio(0); cin.tie(0); cout.tie(0); }
void File()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
}

/**------------------>>  Initialization gap  <<------------------**/

int image[210][210], H, W, CCs, id = 1;
string _in, _table = "WAKJSD";
set <int> neighbours;
char IDs[40010];

map <char, string> Hex_Bin =  {{'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
                               {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
                               {'8', "1000"}, {'9', "1001"}, {'a', "1010"}, {'b', "1011"},
                               {'c', "1100"}, {'d', "1101"}, {'e', "1110"}, {'f', "1111"}};

void ___clear()
{
    CCs = 0; id = 1;
    memset(IDs, 0, sizeof(IDs));
}

bool valid_1(int r, int c)
{
    return r != -1 && c != -1 && r != H && c != W && image[r][c] == 1;
}

bool valid_0(int r, int c)
{
    if(r == -1 || r == H || c == -1 || c == W) // zero beside edges does not belong to a cycle
    {
        neighbours.insert(-1);
        return false;
    }

    if(image[r][c] == -2) return false; // visited
    if(image[r][c] != 0)
    {
        neighbours.insert(image[r][c]); // its neighbour is neither boarder nor -2 so, add it to set
        return false;
    }
    return true;
}

void FloodFill(int r, int c, int _01)
{
    if(_01 == 1)
    {
        if(!valid_1(r, c)) return;
    }
    else
    {
        if(!valid_0(r, c)) return;
    }

    image[r][c] = id;

    for(int i = 0; i < 4; ++i)
        FloodFill(r + dx[i], c + dy[i], _01);
}

void decode(int row, int st, char ch)
{
    string _s = Hex_Bin[ch];
    int idx = 0;

    for(int i = st; i < st + 4; ++i)
        image[row][i] = _s[idx++] - '0';
}

void Solve()
{
    for(int i = 0; i < H; ++i)
    {
        cin >> _in;
        for(int j = 0; j < W; ++j)
            decode(i, j * 4, _in[j]); // Converts each Hex character to its binary equivalent
    }

    W *= 4;

    for(int i = 0; i < H; ++i)
    for(int j = 0; j < W; ++j)
    {
        if(image[i][j] == 1)  // Label each hieroglyph character with a unique color
        {
            ++id; ++CCs;
            FloodFill(i, j, 1);
        }
    }

    id = -2;

    for(int i = 0; i < H; ++i)
    for(int j = 0; j < W; ++j)
        if(image[i][j] == 0)  // if this connected area belongs to one id and only, then increase that id by one
        {
            neighbours.clear();

            FloodFill(i, j, 0);

            if(sz(neighbours) > 1)
                continue;
            else
                IDs[*neighbours.begin()]++;
        }

    string ret = "";

    for(int i = 0; i < 40000; ++i)
        if(IDs[i] > 0)
            ret.push_back(_table[(int)IDs[i]]); // each id is an integer [0, 5] that denotes one of the six hieroglyph characters

    for(int i = sz(ret); i < CCs; ++i)
        ret.push_back('W'); // If the number of hieroglyph characters is less than the actual number, then the number of 'W'  = CCs - ret.size()

    sort(all(ret));
    cout << ret << endl;
}

void MultiTest()
{
    int _tc = 1;

    while(cin >> H >> W && (H || W))
    {
        cout << "Case " << _tc++ << ": ";

        Solve();
        ___clear();
    }
}

/**------------------------->>  Main  <<-------------------------**/

int main()
{
    Fast(); File(); MultiTest();
}
