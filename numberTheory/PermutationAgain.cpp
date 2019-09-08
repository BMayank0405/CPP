/*
 * author: bmayank
 * URL : https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/permutation-again/
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
            int n, m, x = 1;
            cin >> n;
            vector<int> vect;
            m = n;

            while (n > x)
            {
                vect.eb(x);
                vect.eb(n);
                x++;
                n--;
            }
            if (n == x)
                vect.eb(x);
            // forEach(vect)
            // {
            //     cout << value << " ";
            // }
            // cout << "\n";
            ll sum = 0;
            if (m > 1)
            {
                loopab(x, 1, m - 1, 1)
                {
                    sum += abs(vect[x] - vect[x - 1]);
                }
            }
            else
            {
                sum += vect[0];
            }

            cout << sum << "\n";
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    //ending time of program
    return 0;
}
