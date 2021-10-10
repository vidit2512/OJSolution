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

template<typename T>
class Fenwick{
    private:
        vector<T> bit,bit2;
        int n;
        template<typename T1,typename T2>
        void update(T1 id,T2 val ,vector<T> &v){
            while(id<=n) v[id]+= val , id += id & -id;
        }
        template<typename T1>
        T sum(vector<T> &v,T1 id){
            T ans = 0;
            while(id>0) ans+=v[id] , id -= id & -id;
            return ans;
        }
        template<typename T1>
        T pre_sum(T1 id){
            return sum(bit,id)*id - sum(bit2,id);
        }
    public:
        template<typename T1>
        Fenwick(T1 n){
            this->n = n;
            bit.assign(n+2,0);
            bit2.assign(n+2,0);
        }
        template<typename T1,typename T2>
        void r_update(T1 l,T2 r,T val){
            update(l,val,bit);
            update(r+1,-val,bit);
            update(l,val*(l-1),bit2);
            update(r+1,-val*r,bit2);
        }
        template<typename T1,typename T2>
        T r_query(T1 l,T2 r){
            if(l > r) return 0LL;
            return pre_sum(r) - pre_sum(l-1);
        }
};

void __sol(){
    int n; cin >> n;
    vector<int> v(n); cin >> v;
    vector<int> cmp = v;
    unique(cmp);
    for(auto &i: v){
        i = lower_bound(all(cmp) , i) - cmp.begin() + 1;
    }
    ll ans = 0;
    Fenwick<ll> f(cmp.size());
    Fenwick<ll> freq(cmp.size());
    for(auto &i: v){
        ll less = freq.r_query(1 , i - 1);
        ll greater = freq.r_query(i+1 , cmp.size());
        if(less <= greater){
            f.r_update(i , i , less);
        }
        else{
            f.r_update(i , i , greater);
        }
        freq.r_update(i , i , 1);
    }
    for(int i=1;i<=cmp.size();i++){
        ans += f.r_query(i , i);
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