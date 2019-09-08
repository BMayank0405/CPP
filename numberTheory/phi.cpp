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
#define mod (int)(1e6 + 3)
#define power9 (int)(1e9 + 7)
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
    ull t;    \
    cin >> t; \
    while (t--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << "\n"

using namespace std;

ll phi(ull n)
{
    ull result = n;
    for (ull i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }

            result -= result / i;
        }
    }

    if (n > 1)
        result -= result / n;
    return result;
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
        ull n, k;
        cin >> n >> k;
        for (ull i = 0; i < k; ++i)
        {
            n = phi(n);
        }
        cout << n;
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    //ending time of program
    return 0;
}
