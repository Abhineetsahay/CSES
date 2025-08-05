#include <bits/stdc++.h>
#define ll long long int
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define all(s) s.begin(), s.end()

using namespace std;

void dfs(ll node, vector<vector<ll>> &roads, vector<bool> &vis)
{
    vis[node] = true;
    for (auto &it : roads[node])
    {
        if (!vis[it])
        {
            dfs(it, roads, vis);
        }
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> roads(n + 1);

    ll i = 0;
    while (i < m)
    {
        ll u, v;
        cin >> u >> v;
        roads[u].push_back(v);
        roads[v].push_back(u);
        i++;
    }

    vector<bool> vis(n + 1, false);
    vector<ll> res;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i,roads,vis);
            res.push_back(i);
        }
    }
    cout << res.size()-1 << '\n';

     for (ll i = 1; i < res.size(); i++)
    {
        cout << res[i - 1] << " " << res[i] << '\n';
    }
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
