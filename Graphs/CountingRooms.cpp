#include <bits/stdc++.h>
#define ll long long int
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define all(s) s.begin(), s.end()

using namespace std;

vector<ll> dr = {-1, 0, 1, 0};
vector<ll> dc = {0, 1, 0, -1};

void dfs(ll i, ll j, ll n, ll m, vector<vector<bool>> &vis)
{
    vis[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int dx = i + dr[k]; 
        int dy = j + dc[k];
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && !vis[dx][dy])
        {
            dfs(dx, dy, n, m, vis);
        }
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> chars(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> chars[i][j];
            if (chars[i][j] == '#')
            {
                vis[i][j] = true;
            }
        }
    }

    ll cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                dfs(i, j, n, m, vis);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
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
