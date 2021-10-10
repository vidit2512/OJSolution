#include <bits/stdc++.h>
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
    vector<int> a = v;
    sort(all(a));
    vector<vector<int>> ans;
    forr(i,n){
        if(v[i] == a[i]) continue;
        else{
            int id = i;
            for(int j=i;j<n;j++){
                if(v[j] == a[i]){
                    id = j;
                    break;
                }
            }
            vector<int> temp = { i , id , id - i };
            ans.eb(temp);
            int cnt = v[id];
            for(int j=id;j>i;j--){
                v[j] = v[j-1];
            }
            v[i] = cnt;
        }
    }
    cout << ans.size()<<"\n";
    for(auto &i: ans) cout << i[0]+1<<" "<<i[1]+1<<" "<<i[2]<<"\n";
    return;
}


int main(){ 
    fastio;
    int tc=1; cin >> tc;
    while(tc--) __sol();
    return 0;
}