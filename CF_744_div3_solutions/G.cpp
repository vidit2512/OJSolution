#include "bits/stdc++.h"
#define ll long long int
#define oo 1000000000000000000
#define forr(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()
#define unique(v) sort(all(v)); v.resize(distance(v.begin(),unique(all(v))))
#define eb emplace_back
#define FF first
#define SS second
#define mem(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define popcount(x) __builtin_popcount(x)

using namespace std;

template<typename T>
ostream &operator<<(ostream &output,const vector<T> &v){ 
    if(v.empty()) return output;
    for(int i=0;i<v.size()-1;i++) output << v[i] <<" ";
    output << v.back();
    return output;
}
template<typename T>
istream &operator>>(istream &input,vector<T> &v){ 
    for(auto &i: v) cin >> i;
    return input;            
}


void __sol(){
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    int l = *max_element(all(v));
    vector<vector<int>> dp(n+1,vector<int>(2*l+1,INT_MAX/10));
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=2*l;j++){
            dp[i+1][max(0 , j - v[i])] = min(dp[i+1][max(0,j - v[i])] , dp[i][j] + v[i]);
            if(j + v[i]<=2*l){
                dp[i+1][j+v[i]]=min(dp[i+1][j+v[i]] , max(0 , dp[i][j] - v[i]));
            }
        }
    }
    int ans = 2*l + 1;
    for(int i=0;i<=2*l;i++){
        ans = min(ans , i + dp[n][i]);
    }
    cout << ans<<"\n";
    return;
}


int main(){ 
    fastio;
    int tc=1; cin >> tc;
    while(tc--) __sol();
    return 0;
}