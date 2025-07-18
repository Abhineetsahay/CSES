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
    ll a, b;
    cin >> a >> b;

    if ((a + b) % 3 != 0 || a > 2 * b || b > 2 * a)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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
