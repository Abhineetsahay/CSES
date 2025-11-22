#include <bits/stdc++.h>
#define ll long long int
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
const int mod = 1000000007;

vector<vector<ll>> dp;

ll f(int first, int last, vector<int> &x)
{
    if (first > last)
        return 0;

    if (dp[first][last] != -1)
        return dp[first][last];
    return dp[first][last] = max(x[first] - f(first + 1, last, x), x[last] - f(first, last - 1, x));
}
void solve()
{
    int n;
    cin >> n;

    vector<int> x(n);
    dp.assign(n, vector<ll>(n, -1));

    for (int i = 0; i < n; i++)
        cin >> x[i];

    ll diff = f(0, n - 1, x);
    ll total = accumulate(x.begin(), x.end(), 0LL);

    cout << (total + diff) / 2 << endl;
}

int main()
{
    fastIO;
    solve();
    return 0;
}
