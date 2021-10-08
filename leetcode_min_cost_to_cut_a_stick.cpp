#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll rc(int ind, vector<vector<ll>> &dp, int start, int end, vector<int> &cuts, vector<ll> filled)
{

  ll ans = -1;

  for (int i = 0; i < cuts.size(); i++)
  {

    if (start <= cuts[i] && cuts[i] <= end && filled[i] == 0)
    {
      filled[i] = 1;
      if (ans == -1)
      {
        ans = (end - start) + rc(i, dp, start, cuts[i], cuts, filled) + rc(i, dp, cuts[i], end, cuts, filled);
      }
      else
        ans = min(ans, (end - start) + rc(i, dp, start, cuts[i], cuts, filled) + rc(i, dp, cuts[i], end, cuts, filled));
      filled[i] = 0;
    }
  }

  return (ans == -1 ? 0 : ans);
    }
    int minCost(int n, vector<int>& cuts) {
        int nn=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<ll>>dp(nn+1,vector<ll>(n+1,-1));
        vector<ll> filled(n,0);
       ll ans= 0;
           ans=rc(-1,dp,0,n,cuts,filled);

        return ans;
    }

    int main()
{
    int tc=1;
    
    while (tc--)
    {
        int n;
        int length;
        cin >> length;
        cin >> n;
        vector<int> cuts(n);
        for (int i = 0;i<n;i++)
        {
            cin >> cuts[i];
        }
        cout<<minCost(length,cuts)<<endl;

    }
}
