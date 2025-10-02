#include <bits/stdc++.h>
#define ll long long int
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
const int mod = 1000000007;

vector<int> dp;
void solve()
{
    int n;
    cin >> n;
    dp.assign(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        for (int j = 0; j < s.size(); j++)
        {
            int d = s[j] - '0';
            if (d > 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - d]);
            }
        }
    }
    cout << dp[n] << '\n';
}

int main()
{
    fastIO;
    solve();
    return 0;
}
