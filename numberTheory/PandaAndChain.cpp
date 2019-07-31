/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/panda-and-chain-reaction/
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
#define power9 1000000007
#define mod (int)(1e6 + 3)
#define power5 100007
#define totalChars 25
#define P pair<int, int>
//end of shorten coding time

//helper code
#define forEach(c) for (auto &value : c)
#define loopab(loopconstant, startingValue, endingValue, adder) for (loopconstant = (startingValue); loopconstant <= (endingValue); loopconstant += adder)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper, 1)

#define Odd(n) if (n & 1)
#define cases \
    int t;    \
    cin >> t; \
    while (t--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << "\n"

using namespace std;
ll result[1000006] = {0};
ll fact_dp(int n)
{

    if (n >= 0)
    {
        result[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            result[i] = ((i % mod) * (result[i - 1] % mod)) % mod;
        }
        return (result[n] % mod);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    try
    {
        // ifstream mayank("../../testCases.txt");
        // mayank.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
        // if (!mayank.is_open())
        // {
        //     cerr << "Error opening file" << endl;
        //     exit(1);
        // }

        //write your code here

        cases
        {
            ll k, x;
            cin >> k >> x;
            cout << (fact_dp(k) * x) % mod << "\n";
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    //ending time of program
    return 0;
}
