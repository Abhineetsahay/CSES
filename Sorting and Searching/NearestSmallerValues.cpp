#include <bits/stdc++.h>
#define ll long long int
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    // {value, index}
    stack<pair<int, int>> st;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first >= x[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(st.top().second + 1); 
        }

        st.push({x[i], i});
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    fastIO;
    solve();
    return 0;
}
