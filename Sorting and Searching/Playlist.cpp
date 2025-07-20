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

    vector<ll> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];

    map<ll, ll> mp;

    ll left = 0, right = 0;
    ll ans = 0;
    while (right < n)
    {   
        mp[k[right]]++;
        while (mp[k[right]] > 1)
        {
            mp[k[left]]--;
            if (mp[k[left]] == 0)
                mp.erase(k[left]);
            left++;
        }

        ans = max(ans, right - left + 1);
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
