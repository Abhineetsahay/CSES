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
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));

    ll l = 0, r = n - 1;
    ll ans = 0;
    while (r >= l)
    {
        if (a[r] + a[l] <= x)
        {
            l++;
        }
        r--;
        ans++;
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
