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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(all(a));
    sort(all(b));

    ll i = 0, j = 0, ans = 0;

    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= k)
        {
            i++, j++;
            ans++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            i++;
        }
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
