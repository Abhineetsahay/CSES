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
    ll n;
    cin >> n;

    vector<ll> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(all(p));

    ll mid = p[n / 2];

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(p[i] - mid);
    }
    cout << ans << '\n';
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
