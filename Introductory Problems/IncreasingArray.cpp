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
    vector<ll> x(n);

    for (int i = 0; i < n; i++)
        cin >> x[i];

    ll moves = 0;
    for (int i = 1; i < n; i++)
    {
        if (x[i] >= x[i - 1])
        {
            continue;
        }
        moves += (x[i - 1] - x[i]);
        x[i] = x[i - 1];
    }

    cout << moves << '\n';
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
