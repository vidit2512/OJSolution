#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, K;
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        int S[N];
        for (int j = 0; j < N; j++)
        {
            cin >> S[j];
        }
        sort(S, S + N, greater<int>());
        while (S[K] == S[K - 1] && K < N)
        {
            K++;
        }
        cout<<K<<"\n";
    }
    return 0;
}