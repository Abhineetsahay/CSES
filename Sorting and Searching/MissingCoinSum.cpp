#include <bits/stdc++.h>
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    sort(x.begin(), x.end());

    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (x[i] > sum + 1)
            break;
        sum += x[i];
    }

    cout << sum + 1 << '\n';
}

int main()
{
    fastIO;
    solve();
    return 0;
}
