#include <bits/stdc++.h>
#define ll long long int
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

vector<vector<int>> dp;

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    const int INF = 1e9;
    dp.assign(n + 1, vector<int>(x + 1, INF));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= x; j++) 
        {
            dp[i][j] = dp[i - 1][j]; 
            if (c[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - c[i - 1]]);
            }
        }
    }

    int ans = dp[n][x];
    if (ans >= INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

int main()
{
    fastIO;
    solve();
    return 0;
}
