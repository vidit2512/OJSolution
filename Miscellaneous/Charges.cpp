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
        ll n, k, i;
        string s;
        cin >> n >> k;
        cin >> s;

        ll q[k];

        for (i = 0; i < k; i++)
        {
            cin >> q[i];
            // cout<<q[i];
        }

        ll ans = 0;

        for (i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                ans += 2;
            }
            else
            {
                ans += 1;
            }
        }
// cout<<ans<<endl;
        for (i = 0; i < k; i++)
        {
            if (s[q[i] - 1] == '1')
            {
                s[q[i] - 1] = '0';
            }
            else
            {
                s[q[i] - 1] = '1';
            }



          if(q[i]!=n)
          {
 
          if(s[q[i] - 1]==s[q[i]])
          {
              ans=ans+1;
// cout<<"Df";
          }
          else
          {
              ans=ans-1;
          }
           
          }


          if(q[i]!=1)
          {
               if(s[q[i] - 1]==s[q[i]-2])
          {
              ans=ans+1;

          }
          else
          {
              ans=ans-1;
          }
          }
    cout<<ans<<endl;
        }
    }
    return 0;
}