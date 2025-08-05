#include <bits/stdc++.h>
#define ll long long int
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define all(s) s.begin(), s.end()

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<ll> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    ll total = 0, maxTime = 0;

    for (int i = 0; i < n; i++)
    {
        total += t[i];
        maxTime = max(maxTime, t[i]);
    }

    cout << max(total, 2 * maxTime) << '\n';
}

int main()
{
    fastIO;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
