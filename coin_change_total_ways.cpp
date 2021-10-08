#include<bits/stdc++.h>
using namespace std;

//rec+ memo for total number of ways to make a coin
rc(int i,int sum,int den[],vector<vector<int>>&dp)
{
     if(sum==0)
            return 1;
    if(i<0)
        return 0;
    if(sum<0)
        return 0;
        if(dp[i][sum]!=-1)
            return dp[i][sum];

    int ans = rc(i - 1, sum, den,dp) + rc(i, sum - den[i], den,dp);
    return dp[i][sum]=ans;
}
int main()
{
    int tc;
    cin >> tc;
    
    while (tc--)
    {
        int n;
        int sum;
        cin >> sum;
        cin >> n;
        int den[n];
        for (int i = 0;i<n;i++)
        {
            cin >> den[i];
        }
        vector<vector<int>> dp (n,vector<int>(sum+1,-1));

         rc(n - 1, sum, den,dp);
         cout << dp[n - 1][sum] << endl;
    }
}
