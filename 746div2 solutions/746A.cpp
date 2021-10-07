#include<bits/stdc++.h>
#define sync
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sync 

    int t;
    cin>>t;
    while(t--){
		long long int n, h;
        cin>>n>>h;
		long long int ar[n];
		
		for(int i=0; i<n; i++){
			cin >> ar[i];
			
		}
        
		sort(ar,ar+n);
		long long int a = ar[n-1];
        long long int b = ar[n-2];
        if(h<=a)
        {
            cout<<1<<endl;
        }
        else if( h>a && h<=a+b)
        {
            cout<<2<<endl;
        }
        else
        
        {
            long long int k = a+b;
            if(h%k==0)
            {
                cout<<2*(h/k)<<endl;
            }
            else
            {
                long long int sum = 2*(h/k);
                long long int s = h%k;
                if(s<=a)
                {
                    sum++;
                }
                else
                {
                    sum = sum +2;
                }
                cout<<sum<<endl;
            }
        }

		
	}

  return 0;
}


