#include <bits/stdc++.h>
using namespace std;


// recursion only approch
int rc(int i,int len[],int profit[],int tot)
{
    int ans = 0;
    if(i<=0)
        return 0;
    if(len[i]<=tot)
        ans = max(ans,max(profit[i]+ rc(i, len, profit, tot - len[i]), rc(i - 1, len, profit, tot)  ));
else
    ans = max(ans,rc(i - 1, len, profit, tot));
return ans;
}  

//recursion with momoization
int rcmem(int i,int len[],int profit[],int tot,vector<vector<int>>&dp)
{
    int ans = 0;
    if(i<=0)
        return 0;
        if(dp[i][tot]!=-1)
            return dp[i][tot];
    if(len[i]<=tot)
        ans = max(ans,max(profit[i]+ rcmem(i, len, profit, tot - len[i],dp), rcmem(i - 1, len, profit, tot,dp)  ));
else
    ans = max(ans,rcmem(i - 1, len, profit, tot,dp));
return dp[i][tot]=ans;
}  

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        int profit[n];
        int len[n];
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
            for (int i = 0; i < n; i++)
            {
                cin >> profit[i];
                len[i] = i + 1;
            }
        int ans = rcmem(n-1, len, profit, n,dp);
        cout << ans << endl;
    }
    return 0;
}
