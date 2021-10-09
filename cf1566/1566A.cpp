#pragma  GCC optimize("O3")
#include <bits/stdc++.h>
#define ll               long long int
#define bhaago           ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define loop(a,b,i)      for(ll i=a;i<b;i++)
#define loop1(a,b,i)     for(ll i=a;i>b;i--)
#define printclock       cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define endl              '\n'
#define Endl              '\n'
#define all(v)           (vector.begin(),vector.end())
#define az(i)            for(auto it:i)cout<<it<<" ";cout<<Endl;
#define mpaz(i)          for(auto it:i)cout<<it.first<<"->"<<it.second<<endl;cout<<Endl;
#define araz(arr,i)      loop(0,i,j)cout<<arr[j]<<" ";cout<<Endl;
#define setin(s,i)       for(auto it:i)s.insert(it);
#define mpin(mp,i)       for(auto it:i)mp[it]++;
#define yy               cout<<"YES"<<endl
#define nn               cout<<"NO"<<endl
#define prn1(tk,ans)      cout<<"Case #"<<tk<<": "<<ans<<endl
#define prn(tk)          cout<<"Case #"<<tk<<": "
#define init(dp,i)       memset(dp,i,sizeof dp)
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
const double pi = std::acos(-1);
using namespace std;
const ll mod = 1000000000+7;
 
 
ll power(ll x,ll y,ll md)  
{ll res=1;x=x%md;if(x==0)return 0;while(y>0){if(y&1)res=(res*x)%md;y=y>>1;x=(x*x)%md;}return res;} 
 
ll m_mul(ll a, ll b){a=a%mod;b=b%mod;return (a*b+mod)%mod;}
ll m_add(ll a,ll b){a=a%mod; b=b%mod;return (a+b+mod)%mod;}
 
ll spf[(ll)1e7+2]={0};
 
struct dsu{
vector<ll>parent,rank;
dsu(ll n)
{parent.resize(n+2); for(ll i=0;i<=n;i++)parent[i]=i;rank.resize(n+2);}
ll fnd(ll i)
{if(parent[i]==i)return i;else return parent[i]=fnd(parent[i]);}
void unite(ll a,ll b)
{  a=fnd(a);b=fnd(b);if(rank[a]>rank[b])parent[b]=a;else if(rank[b]>rank[a])parent[a]=b;else{parent[a]=b;rank[b]++;}}
bool same(ll a,ll b)
{return fnd(a)==fnd(b);}
};
//------------------------------------------------------
struct sgtree
{
vector<ll> arr;vector<ll> tree, lazy;
 
sgtree(ll n, ll brr[])
{arr.resize(n);ll k = 2 * (ll)powl(2, log2l(n) + 1);tree.resize(k);lazy.resize(k);
loop(0, k, i) lazy[i] = -1;//here*//this is veryyy imp., here dummyy value is to be kept., then to change all conditions where dummy is checked.!!
loop(0, n, i)arr[i] = brr[i];}
 
void build(ll ind, ll left, ll right)
{if (left == right){tree[ind] = arr[left];return;}
ll mid = left + (right - left) / 2;
build(2 * ind + 1, left, mid);build(2 * ind + 2, mid + 1, right);
tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];}
 
void updateSingle(ll ind, ll index, ll val, ll left, ll right) //after arr[index]=val
{if (left == right && left == index){tree[ind] =val;return;}
if (index > right || index < left)return;
ll mid = left + (right - left) / 2;
updateSingle(2 * ind + 1, index, val, left, mid);updateSingle(2 * ind + 2, index, val, mid + 1, right);
tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];}
 
void updateLazy(ll ind, ll indexleft, ll indexright, ll val, ll left, ll right) //upadte value in a range
{if (lazy[ind] != -1)//here*
{tree[ind] =  (right-left+1)*lazy[ind]; //here you can make changes as req.
if (left != right){lazy[2 * ind + 1] = lazy[ind];lazy[2 * ind + 2] = lazy[ind];}
lazy[ind] = -1;//here*
}
if (indexleft > right || indexright < left)return;
if (indexleft <= left && right <= indexright)
{tree[ind] = (right-left+1)* val; //here you can make changes as req.
if (left != right)
{lazy[2 * ind + 1] = val;lazy[2 * ind + 2] = val;}return;}
ll mid = left + (right - left) / 2;
updateLazy(2 * ind + 1, indexleft, indexright, val, left, mid);
updateLazy(2 * ind + 2, indexleft, indexright, val, mid + 1, right);
tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
}
ll ans(ll ind, ll start, ll end, ll left, ll right) //start, end are query for l and r
{if (lazy[ind] != -1)//here*
{tree[ind]=(right-left+1)*lazy[ind]; //here you can make changes as req.
if (left!=right){lazy[2*ind+1]=lazy[ind];lazy[2*ind+2]=lazy[ind];}
 lazy[ind] = -1;//here*
}
if (left>end||start>right)return 0;
if (start<=left && right<=end)return tree[ind];
ll mid=left+(right-left)/2;
return ans(2*ind+1,start,end,left,mid)+ans(2*ind+2,start,end,mid+1,right);
}
};
//------------------------------------------------------
void siv()
{
spf[1]=1;
loop(1,1e7+2,i)spf[i]=i;
loop(2,1e7+2,i)spf[i]=2,i++;
for(ll i=3;i*i<(ll)1e7+2;i++)
{if( spf[i]==i)for(ll j=i*i;j<(ll)1e7+2;j=j+i)if(spf[j]==j)spf[j]=i;}
}
//---------------------------------------------------
 
int main() {
//see if tcs are present or not.
      bhaago;
      // freopen("@iin.txt","r",stdin);
      // freopen("@output.txt","w",stdout);
    ll tc=1;
    cin>>tc;
    while(tc--)
    {
        ll n,s;
        cin>>n>>s;
        int ab=n/2;
        if(n%2==0)ab=(n-1)/2;
       cout<<s/(n-ab)<<endl;
    
    }
	// your code goes here
	return 0;
}
