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
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    unordered_map<ll, ll> mp;
    ll left = 0, right = 0;

    ll ans = 0;
    while (right < n)
    {
        mp[x[right]]++;

        while (mp.size() > k)
        {
            mp[x[left]]--;
            if (mp[x[left]] == 0)
            {
                mp.erase(x[left]);
            }
            left++;
        }
        ans += (right - left + 1);
        right++;
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
