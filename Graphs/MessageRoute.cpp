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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // wt, nextNode
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n + 1, INT_MAX);
    vector<int> vis(n + 1);

    iota(all(vis), 1);

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > dist[node])
            continue;

        for (auto &it : adjList[node])
        {
            if (dist[it] > cost + 1)
            {
                dist[it] = cost + 1;
                vis[it] = node;
                pq.push({cost + 1, it});
            }
        }
    }
    if (dist[n] == INT_MAX)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> ans;
    int i = vis[n];
    ans.push_back(n);
    while (i != 1)
    {
        ans.push_back(i);
        i = vis[i];
    }
    ans.push_back(i);
    reverse(all(ans));

    cout << ans.size() << '\n';

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main()
{
    fastIO;
    solve();

    return 0;
}
