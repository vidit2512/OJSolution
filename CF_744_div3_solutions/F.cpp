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
    int n,d; cin >> n >> d;
    d = n - d;
    vector<int> v(n); cin >> v;
    if(d == 0){
        if(count(all(v),1)) cout <<"-1\n";
        else cout << 0<<"\n";
        return;
    }
    vector<int> vis(n);
    auto get = [&](vector<int> &a) -> int{
        // cout << a<<"\n";
        if(count(all(a) , 1) == 0){
            return 0;
        }
        if(count(all(a) , 1) == a.size()){
            return -1;
        }
        int i = 0;
        for(;i<a.size();i++){
            if(!a[i]) break;
        }
        int sz = a.size();
        i %= sz;
        for(;;){
            if(a[i]) break;
            i++;
            i %= sz;
        }
        int cnt = 0;
        int ans = 0;
        forr(j,sz){
            if(a[i]) cnt++;
            else{
                ans = max(ans , cnt );
                cnt = 0;
            }
            i++;
            i%=sz;
        }
        ans = max(ans , cnt );
        return ans;
    };
    int ans = 0;
    forr(i,n){
        if(!vis[i]){
            int st = i;
            vector<int> temp;
            while(!vis[st]){
                temp.eb(v[st]);
                vis[st] = 1;
                st = (st + d)%n;
            }
            int cnt = get(temp);
            if(cnt == -1){
                cout <<cnt<<"\n";
                return;
            }
            ans = max(ans , cnt);
        }
    }
    cout << ans<<"\n";
    return;
}


int main(){ 
    fastio;
    int tc=1;  cin >> tc;
    while(tc--) __sol();
    return 0;
}