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
    ll y, x;

    cin >> y >> x;

    ll i = max(y, x);

    ll sq = i * i;

    if (i % 2 == 0)
    {
        if (y == i)
        {
            cout << sq - (x - 1) << '\n';
        }
        else
        {
            cout << (i - 1) * (i - 1) + y << '\n';
        }
    }
    else
    {
        if (x == i)
        {
            cout << sq - (y - 1) << '\n';
        }
        else
        {
            cout << (i - 1) * (i - 1) + x << '\n';
        }
    }
}

int main()
{
    fastIO;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
