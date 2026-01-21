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

    vector<pair<pair<int, int>, int>> rooms;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        rooms.push_back({{a, b}, i});
    }
    sort(rooms.begin(), rooms.end());
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    vector<int> ans(n);

    int room = 0;
    for (int i = 0; i < n; i++)
    {
        int a = rooms[i].first.first;
        int b = rooms[i].first.second;
        int ind = rooms[i].second;

        if (!pq.empty() && pq.top().first < a)
        {
            ans[ind] = pq.top().second;
            pq.pop();
            pq.push({b, ans[ind]});
        }
        else
        {
            room++;
            ans[ind] = room;
            pq.push({b, room});
        }
    }
    cout << room << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{
    fastIO;
    solve();
    return 0;
}
