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
    ll n, q;
    cin >> n >> q;

    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    vector<ll> prefSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefSum[i] = x[i - 1] + prefSum[i - 1];
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << prefSum[b] - prefSum[a - 1] << '\n';
    }
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
