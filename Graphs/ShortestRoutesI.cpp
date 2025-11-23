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

    vector<vector<pair<int, int>>> adjList(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        adjList[a].push_back({b, c});
    }

    // wt, nextNode
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    pq.push({0, 1});

    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = 0;

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        if (dis > dist[node])
            continue;
        for (auto &it : adjList[node])
        {
            if (dist[node] + it.second < dist[it.first])
            {
                pq.push({dist[node] + it.second, it.first});
                dist[it.first] = dist[node] + it.second;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    fastIO;
    solve();

    return 0;
}
