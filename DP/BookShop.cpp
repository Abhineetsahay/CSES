#include <bits/stdc++.h>
#define ll long long int
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
const int mod = 1000000007;
// h-> price
// s->page

vector<vector<int>> dp;

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    dp.assign(n + 1, vector<int>(x + 1, 0));

    // for (int i = 0; i <= n; i++)
    // {
    //     dp[i][0] = 0;
    // }
    // for (int i = 0; i <= x; i++)
    // {
    //     dp[0][i] = 0;
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= x; j++)
    //     {
    //         if (h[i - 1] <= j)
    //         {
    //             dp[i][j] = max(dp[i - 1][j], s[i - 1] + dp[i - 1][j - h[i - 1]]);
    //         }
    //         else
    //         {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //     }
    // }

    vector<int> prev(x + 1, 0), curr(x + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (h[i - 1] <= j)
            {
                curr[j] = max(prev[j], s[i - 1] + prev[j - h[i - 1]]);
            }
            else
            {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    cout << prev[x] << '\n';
}

int main()
{
    fastIO;
    solve();
    return 0;
}
