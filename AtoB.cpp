#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define MOD 1000000007LL
LL power(LL a, LL b, LL mod)
{
    LL x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y);
            if (x > mod)
                x %= mod;
        }
        y = (y * y);
        if (y > mod)
            y %= mod;
        b /= 2;
    }
    return x;
}
int main()
{
    int N, A, B, query, pos;
    cin >> N;
    LL a[N], product = 1, zeros = 0, value;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i])
            product = (product * a[i]) % MOD;
        else
            zeros++;
    }
    cin >> query;
    while (query--)
    {
        cin >> A;
        if (A)
        {
            cin >> B;
            B--;
            //Get Answer
            if ((!a[B]) && zeros == 1)
                cout << product << endl;
            if ((!a[B]) && zeros > 1)
                cout << 0 << endl;
            if (a[B] && zeros > 0)
                cout << 0 << endl;
            if (a[B] && zeros == 0)
                cout << (product * power(a[B], MOD - 2, MOD)) % MOD << endl;
        }
        else
        {
            cin >> pos >> value;
            pos--;
            if ((!a[pos]) && value)
            {
                a[pos] = value;
                product = (product * value) % MOD;
                zeros--;
            }
            if (a[pos] && (!value))
            {
                product = (product * power(a[pos], MOD - 2, MOD)) % MOD;
                zeros++;
                a[pos] = 0;
            }
            if (a[pos] && value)
            {
                product = (product * value) % MOD;
                product = (product * power(a[pos], MOD - 2, MOD)) % MOD;
                a[pos] = value;
            }
        }
    }
    return 0;
}