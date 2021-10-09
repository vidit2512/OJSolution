#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
const ll mod = 1000000000 + 7;

ll power(ll x, ll y, ll md)
{
    ll res = 1;
    x = x % md;
    if (x == 0)
        return 0;
    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % md;
        y = y >> 1;
        x = (x * x) % md;
    }
    return res;
}

ll m_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (a * b + mod) % mod;
}

ll m_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (a + b + mod) % mod;
}

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(u, adj, visited);
    }
}

int main()
{
    ll t;

    cin >> t;

    while (t--)
    {

        ll n, m;
        cin >> n;
        ll i, a[2 * n];
        ll b[n + 1];

        vector<vector<int>> adj(2 * n);

        for (i = 0; i < 2 * n; i++)
        {
            cin >> a[i];

            if (i > n - 1)
            {

                adj[i].push_back(b[a[i]]);

                adj[b[a[i]]].push_back(i);

                adj[i].push_back(i - n);

                adj[i - n].push_back(i);
            }
            else
            {
                b[a[i]] = i;
            }
        }

        vector<bool> visited(2 * n, 0);

        int c = 0;

        for (i = 0; i < 2 * n; i++)
        {
            if (!visited[i])
            {
                // cout << i << endl;
                c++;
                dfs(i, adj, visited);
            }
        }
        // cout << c << endl;
        cout << power(2, c, 1000000007) << endl;
        ;
    }
    return 0;
}