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

    ll t = 0;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;
        ll n = s.length();

        string first = s, second = s;
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0 && s[i] == '?')
            {

                first[i] = '1';
            }
            else if (i % 2 == 1 && s[i] == '?')
            {
                first[i] = '0';
            }
        }

        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0 && s[i] == '?')
            {

                second[i] = '0';
            }
            else if (i % 2 == 1 && s[i] == '?')
            {
                second[i] = '1';
            }
        }

        ll c = 0, cc = 0;
        ll gg = 10;
        // cout << first << endl;

        for (ll i = 0; i < n; i++)
        {

            if (i % 2 == 0)
            {
                if (first[i] == '1')
                    c++;
                if (c - cc > 5 - i / 2)
                {
                    gg = i+1;
                    break;
                }
            }
            else
            {
                if (first[i] == '1')
                    cc++;

                if (c - cc > 5 - (i + 1) / 2)
                {
                    gg = i+1;
                    break;
                }
            }
        }

        c = 0, cc = 0;
        ll ggg = 10;
        for (ll i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (second[i] == '1')
                    c++;

                if (cc - c > 5 - ((i / 2)+1))
                {
                    ggg = i+1;
                    break;
                }
            }
            else
            {
                if (second[i] == '1')
                    cc++;

                if (cc - c > 5 - (i + 1) / 2)
                {
                    ggg = i+1;
                    break;
                }
            }
        }
        // cout << gg << ggg << endl;
        cout << min(gg, ggg) << endl;
    }
    return 0;
}