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

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<ll, ll> mp;
    mp[0] = 1;
    ll ans = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ll rem = (sum % n + n) % n;

        ans += mp[rem];
        mp[rem]++;
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
