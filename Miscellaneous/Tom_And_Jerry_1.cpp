#include <bits/stdc++.h>
#define ll               long long int
#define endl              '\n'
using namespace std;
const ll mod = 1000000000+7;
 
ll power(ll x,ll y,ll md)  
{  
   ll res=1;     
    x = x % md; 
    if (x == 0) return 0; 
    while (y > 0)  
    {  
   
        if (y & 1)  
       res = (res*x)%md;  
        y = y>>1; 
        x = (x*x)%md;  
    }  
    return res;  
}  
 
ll m_mul(ll a, ll b)
{
    a=a%mod;
    b=b%mod;
    return (a*b+mod)%mod;
}

ll m_add(ll a,ll b)
{
    a=a%mod;
    b=b%mod;
    return (a+b+mod)%mod;
}


void SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}
int main() {
  ll t;
  
  cin>>t;
  
	while(t--)
{

    ll a,b,c,d,k;

   cin>>a>>b>>c>>d>>k;


   ll sum = abs(c-a)+abs(b-d);
// cout<<sum<<endl;
   if(sum>k)
   {
     cout<<"NO"<<endl;
   }
   else{
//    cout<<"Dsfgs";
       if((k-sum)%2==0)
       {
           cout<<"YES"<<endl;
       }
       else{
           cout<<"NO"<<endl;
       }
   }




}
	return 0;
}