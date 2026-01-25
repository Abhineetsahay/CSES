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
    int n;
    cin >> n;

    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    map<ll, ll> freqTrack;

    ll left = 0, right = 0;
    ll count = 0;
    while (right < n)
    {
        freqTrack[x[right]]++;

        while (freqTrack[x[right]] > 1)
        {
            freqTrack[x[left]]--;
            if (freqTrack[x[left]] == 0)
            {
                freqTrack.erase(x[left]);
            }
            left++;
        }
        count += (right - left + 1);
        right++;
    }
    cout << count << '\n';
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
