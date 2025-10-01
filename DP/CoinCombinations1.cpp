#include <bits/stdc++.h>
#define ll long long int
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
const int mod = 1000000007;

void solve()
{
    int n, x;
    cin >> n >> x;
    
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int sum = 1; sum <= x; sum++)
        {
            dp[i][sum] = 0;
            for (int k = 0; k < i; k++)
            {
                if (sum - c[k] >= 0)
                    dp[i][sum] = (dp[i][sum] + dp[i][sum - c[k]]) % mod;
            }
        }
    }
    
    cout << dp[n][x] << '\n';
}

int main()
{
    fastIO;
    solve();
    return 0;
}
