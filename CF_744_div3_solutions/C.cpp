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
    int n , m , k; cin >> n >> m >> k;
    vector<string> v(n); cin >> v;
    vector<vector<bool>> vis(n , vector<bool>(m , false));
    auto getDis = [&](int i,int j){
        int r = i , c1 = j , c2 = j;
        int cnt = -1;
        while(r>=0 && c1>=0 && c2<m){
            if(v[r][c1]!='*' || v[r][c2]!='*') break;
            cnt++;
            r-- , c1-- , c2++;
        }
        return cnt;
    };
    auto visit = [&](int i,int j){
        int r = i , c1 = j , c2 = j;
        while(r>=0 && c1>=0 && c2<m){
            if(v[r][c1]!='*' || v[r][c2]!='*') break;
            vis[r][c1] = vis[r][c2] = 1;
            r-- , c1-- , c2++;
        }
        return;
    };
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(v[i][j]=='*'){
                int d = getDis(i , j);
                if(d >= k) visit(i , j);
            }
        }
    }
    forr(i,n){
        forr(j,m){
            if( v[i][j]=='*' && !vis[i][j] ){
                cout <<"NO\n";
                return;
            }
        }
    }
    cout <<"YES\n";
    return;
}


int main(){ 
    fastio;
    int tc=1; cin >> tc;
    while(tc--) __sol();
    return 0;
}