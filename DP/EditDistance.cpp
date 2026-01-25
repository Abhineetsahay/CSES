#include <bits/stdc++.h>
#define ll long long int
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
const int mod = 1000000007;

string a, b;
vector<vector<int>> dp;

int f(int i, int j)
{
    if (i == a.size())
        return b.size() - j;

    if (j == b.size())
        return a.size() - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i] == b[j])
        return dp[i][j] = f(i + 1, j + 1);

    int insertOp = f(i, j + 1);
    int deleteOp = f(i + 1, j);
    int replaceOp = f(i + 1, j + 1);

    return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
}

void solve()
{
    cin >> a >> b;

    dp.assign(a.size(), vector<int>(b.size(), -1));

    cout << f(0, 0);
}

int main()
{
    fastIO;
    solve();
    return 0;
}
