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

    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(all(a));

    ll i = 0, j = n - 1;
    while (i < j)
    {
        ll sum = a[i].first + a[j].first;
        if (sum == x)
        {
            cout << a[i].second << " " << a[j].second << "\n";
            return;
        }
        else if (sum < x)
        {
            ++i;
        }
        else
        {
            --j;
        }
    }

    cout << "IMPOSSIBLE\n";
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
