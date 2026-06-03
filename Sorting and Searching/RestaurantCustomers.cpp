#include <bits/stdc++.h>
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long int

using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n), dept(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i] >> dept[i];
    }

    sort(arr.begin(), arr.end());
    sort(dept.begin(), dept.end());

    int i = 0, j = 0;
    int current = 0, ans = 0;

    while (i < n && j < n) {
        if (arr[i] < dept[j]) {
            current++;
            ans = max(ans, current);
            i++;
        } else {
            current--;
            j++;
        }
    }

    cout << ans << '\n';
}

int main() {
    fastIO;
    solve();
    return 0;
}
