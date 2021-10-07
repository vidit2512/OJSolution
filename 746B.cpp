#include<bits/stdc++.h>
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb(a) push_back(a);
#define ll long long int
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		int n, x, i, k;
		vector<int>v;
		vector<int>v1;
		cin >> n >> k;
		for(i=0; i<n; i++){
			cin >> x;
			v.pb(x);
			v1.pb(x);
		}
		int f=0;
		sort(v1.begin(), v1.end());
		for(i=0; i<n; i++){
			if(v[i]==v1[i])continue;
			else{
				if(i<k && n-1-i<k){
					f=1;
					break;
				}
			}
		}
		if(f==0){
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
}