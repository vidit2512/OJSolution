#include <iostream>
#include <string.h>
using namespace std;
int check(int n, int h[])
{
    int i = 0, j = 1, t = 0;
    if (n % 2 == 0){
        return 0;
    }
    else if (h[0] == 1)
    {
        while (i < n)
        {
            if (i < n / 2)
            {
                if (h[i] != j)
                {
                    return 0;
                }
                else
                {
                    j++;
                    i++;
                }
            }
            else
            {
                if (h[i] != j)
                {
                    return 0;
                }
                else
                {
                    j--;
                    i++;
                }
            }
        }
    }
    else  return 0;
        return 1;
}
int main()
{
    int S, N, T;
    int H[100];
    cin >> S;
    for (int i = 0; i < S; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> H[j];
        }
        T = check(N, H);
        if (T == 1)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}
