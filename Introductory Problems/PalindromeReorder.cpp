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
    string s;
    cin >> s;
    int n = s.length();

    unordered_map<char, int> mp;
    for (char &c : s)
        mp[c]++;

    int oddCnt = 0;
    char oddChar = 0;
    for (auto &it : mp)
    {
        if (it.second % 2 == 1)
        {
            oddCnt++;
            oddChar = it.first;
        }
    }

    if ((n % 2 == 0 && oddCnt > 0) || (n % 2 == 1 && oddCnt != 1))
    {
        cout << "NO SOLUTION\n";
        return;
    }

    string half = "";
    for (auto &it : mp)
    {
        for (int i = 0; i < it.second / 2; i++)
            half += it.first;
    }

    string palindrome = half;
    if (oddCnt == 1)
    {
        palindrome += string(mp[oddChar] % 2, oddChar);
    }
    reverse(all(half));
    palindrome += half;

    cout << palindrome << '\n';
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
