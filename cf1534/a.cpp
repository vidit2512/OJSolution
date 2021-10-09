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

int main()
{
    ll t;

    cin >> t;

    while (t--)
    {

        ll n, m;
        cin >> n >> m;
        ll i, j;
        char a[n][m];
        char b[n][m];
        char c[n][m];

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {

                cin >> a[i][j];
                if ((i + j) % 2 == 0)
                {
                    b[i][j] = 'R';
                    c[i][j] = 'W';
                }
                else
                {
                    c[i][j] = 'R';
                    b[i][j] = 'W';
                }
            }
        }

        ll g = 0, gg = 0;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {

                if (a[i][j] != '.')
                {

                    if (a[i][j] != b[i][j])
                    {
                        g = 1;
                    }
                    if (a[i][j] != c[i][j])
                    {
                        gg = 1;
                    }
                }
            }
        }

        if (g == 1 && gg == 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                {

                    if (g == 0)
                    {
                        cout << b[i][j];
                    }
                    else
                    {
                        cout << c[i][j];
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}