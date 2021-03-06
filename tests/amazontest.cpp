/*
 * author: bmayank
 * URL : PROBLEM_URL
 */

#include <bits/stdc++.h>

//optimization of program
#define eb emplace_back
#define gc getchar_unlocked
//end of optmization

//shorten coding time
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define power9 (int)(1e9 + 7)
#define totalChars 25
#define Pi pair<int, int>
#define vec vector
#define vi vec<int>
#define vll vec<ll>
#define vull vec<ull>
//end of shorten coding time

//helper code
#define forEach(c) for (auto &value : c)
#define loopab(loopconstant, startingValue, endingValue, adder) for (loopconstant = (startingValue); loopconstant <= (endingValue); loopconstant += adder)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper, 1)

#define Odd(n) if (n & 1)
#define cases \
    ull t;    \
    cin >> t; \
    while (t--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << "\n"

const char lineEnd = '\n';

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    try
    {
        int t;
        cin >> t;
        set<ll> s;
        s.insert(0);
        s.insert(11);
        while (t--)
        {
            int X;
            cin >> X;
            s.insert(X);
            ll sum = 0;
            for (auto itr = s.begin(); next(itr, 2) != s.end(); ++itr)
            {
                sum += *itr + 1 + *(next(itr, 2)) - 1;
            }
            cout << sum << lineEnd;
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << lineEnd;
    }

    return 0;
}
