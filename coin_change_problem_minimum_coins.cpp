#include<bits/stdc++.h>
using namespace std;
//rc with memo to find min coins deno
int rc(int i,int sum,int den[],vector<vector<int>>&dp)
{
    int ans;
    if(sum==0)
        return 0;
        if(sum<0||i<0)
            return INT_MAX-1;
            if(dp[i][sum]!=-1)
                return dp[i][sum];

                       ans = min(rc(i - 1, sum, den, dp), 1 + rc(i, sum - den[i], den, dp));
    return dp[i][sum]=ans;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        int sum;
        cin >> sum;
        cin >> n;
        int den[n];
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        for (int i = 0; i < n;i++)
        {
            cin >> den[i];
        }
        int ans = rc(n - 1, sum, den,dp);
        cout << ans << endl;
    }
    return 0;
}
