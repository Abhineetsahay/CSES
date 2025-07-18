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

    vector<pair<ll, ll>> movies(n);
    for (int i = 0; i < n; i++)
    {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        return a.second < b.second;
    });

    ll ans = 0;
    ll last_end_time = 0;

    for (auto movie : movies)
    {
        if (movie.first >= last_end_time)
        {
            ans++;
            last_end_time = movie.second;
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
