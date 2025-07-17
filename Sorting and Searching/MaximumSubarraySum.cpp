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
    {
        cin >> x[i];
    }

    ll sum = 0;
    ll maxsum = LLONG_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += x[i];

        maxsum=max(maxsum,sum); 
        if (sum < 0) sum = 0;
    }
    cout << maxsum << '\n';
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
