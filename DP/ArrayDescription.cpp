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
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    dp.assign(n + 1, vector<int>(m + 2, 0));

    if (x[0] == 0)
    {
        for (int val = 1; val <= m; val++)
            dp[0][val] = 1;
    }
    else
    {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if (x[i] == 0)
        {
            for (int val = 1; val <= m; val++)
            {
                ll ways = dp[i - 1][val];
                if (val > 1)
                    ways = (ways + dp[i - 1][val - 1]) % mod;
                if (val < m)
                    ways = (ways + dp[i - 1][val + 1]) % mod;
                dp[i][val] = ways % mod;
            }
        }
        else
        {
            int val = x[i];
            ll ways = dp[i - 1][val];
            if (val > 1)
                ways = (ways + dp[i - 1][val - 1]) % mod;
            if (val < m)
                ways = (ways + dp[i - 1][val + 1]) % mod;
            dp[i][val] = ways % mod;
        }
    }
    ll ans = 0;
    for (int val = 1; val <= m; val++)
    {
        ans = (ans + dp[n - 1][val]) % mod;
    }
    cout << ans << "\n";
}

int main()
{
    fastIO;
    solve();
    return 0;
}
