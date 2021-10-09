#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        int a[n + 1], b[n + 1];
        a[0]=0;
        b[0]=0;
        for (int i = 1; i < n + 1; i++)
            cin >> a[i];
        for (int i = 1; i < n + 1; i++)
            cin >> b[i];
        for (int i = 1; i < n + 1; i++)
            if (a[i] - a[i - 1] >= b[i])
                ans++;
        cout << ans << endl;
    }
    return 0;
}