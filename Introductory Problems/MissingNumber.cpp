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

    ll sum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        ll x;
        cin >> x;
        sum += x;
    }

    ll totalSum = n * (n + 1) / 2;

    cout << totalSum - sum << '\n';
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
