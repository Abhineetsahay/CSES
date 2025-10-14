#include <bits/stdc++.h>
#define ll long long int
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
const int mod = 1000000007;

vector<vector<int>> dp;

void solve()
{
    int n;
    cin >> n;
    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = grid[0][0] == '.' ? 1 : 0;

    for (int i = 1; i < n; i++)
        dp[i][0] = (grid[i][0] == '.') ? dp[i - 1][0] : 0;

    for (int j = 1; j < n; j++)
        dp[0][j] = (grid[0][j] == '.') ? dp[0][j - 1] : 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[n - 1][n - 1] << '\n';
}

int main()
{
    fastIO;
    solve();
    return 0;
}
