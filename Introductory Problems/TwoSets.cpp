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

    ll sum = n * (n + 1) / 2;

    if (sum % 2 == 1)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    vector<ll> a, b;
    ll target = sum / 2;

    for (ll i = n; i >= 1; --i)
    {
        if (target >= i)
        {
            a.push_back(i);
            target -= i;
        }
        else
        {
            b.push_back(i);
        }
    }

    cout << a.size() << '\n';
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';

    cout << b.size() << '\n';
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << '\n';
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
