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
        ll n;
        cin >> n;
        string s, ss;
        cin >> s >> ss;

        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            if ((s[i] == '0' && ss[i] == '1') || (ss[i] == '0' && s[i] == '1'))
            {
                ans = ans + 2;
            }
            else if (s[i] == '0' && ss[i] == '0')
            {
                if (i + 1 < n && (s[i + 1] == '1' && ss[i + 1] == '1'))
                {
                    ans = ans + 2;
                    s[i + 1] = '5';
                    ss[i + 1] = '5';
                }
                else
                {
                    ans = ans + 1;
                }
            }
            else if (s[i] == '1' && ss[i] == '1')
            {
                if (i + 1 < n && (s[i + 1] == '0' && ss[i + 1] == '0'))
                {
                    ans = ans + 2;
                    s[i + 1] = '5';
                    ss[i + 1] = '5';
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}