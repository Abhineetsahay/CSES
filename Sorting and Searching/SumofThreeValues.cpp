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
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;  
    }

    sort(all(a)); 

    for (int i = 0; i < n; i++) {
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            ll sum = a[i].first + a[j].first + a[k].first;
            if (sum == x) {
                cout << a[i].second << " " << a[j].second << " " << a[k].second << '\n';
                return;
            }
            else if (sum < x)
                ++j;
            else
                --k;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main()
{
    fastIO;
    solve();
    return 0;
}
