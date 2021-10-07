#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long

const int N = 1e5 + 5;
vector<int> adj[N];
int val[N], xor_arr[N];
bool vis[N];
int cnt = 0;

int dfs1(int u)
{
    xor_arr[u] = val[u];
    vis[u] = true;

    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            xor_arr[u] ^= dfs1(v);
        }
    }
    return xor_arr[u];
}

int dfs2(int u)
{
    vis[u] = true;
    int tmp = val[u];
    for (auto v : adj[u])
    {
        if (!vis[v]){
            tmp ^= dfs2(v);
    //    cout<<u<<" "<<tmp<<endl;
    }
    }
        if (tmp == xor_arr[0])
        {
            tmp = 0;
            // cout<<v<<"tree"<<endl;
            cnt++;
        }
    return tmp;
}

int32_t main(){
    int t = 1;
    cin >> t;
    while (t--){
        int n, k, u, v;
        cin >> n >> k;

        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
            vis[i] = false;
        }

        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs1(0);
        
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
        }
        bool ans = false;
        if (xor_arr[0] == 0)
        {
            ans = true;
        }
        else
        {
            dfs2(0);
            if (cnt >= 2 and k != 2)
            {
                ans = true;
            }
        }
        cout << (ans ? "YES" : "NO") <<endl;
        cnt =0 ;
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            xor_arr[i] = val[i] = 0;
        }
    }
}