#include <iostream>
using namespace std;

int check(int,char *);

int main()
{
    int R, L,T;
    char str[500];
    cin >> R;
    for (int i = 0; i < R; i++)
    {
        cin >> L;
        cin >> str;
        T=check(L,str);
        if(T==0) cout<<"Valid"<<endl;
        else cout<<"Invalid"<<endl;
    }
    return 0;
}
int check(int l, char *St)
{
    int j = 0, T=0;
    while (j < l)
    {
        if (St[j] == '.')
        {
            j++;
            continue;
        }
        else if (St[j] == 'H' && T == 0)
        {
            T = 1;
            j++;
        }
        else if (St[j] == 'T' && T == 1)
        {
            T = 0;
            j++;
        }
        else
        {
            T = 1;
            break;
        };
    }
    if (T == 0)
    {
        return 0;
    }
    else if (T == 1)
    {
        return 1;
    }
}