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
#define cases    \
    long long t; \
    cin >> t;    \
    while (t--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << "\n"

using namespace std;
#define N 1000000
bool isPrime[N + 1];
int val[N + 1];
void sieve()
{
    int i;
    loop(i, N)
    {
        isPrime[i] = true;
        val[i] = 0;
    }
    for (int i = 2; i * i <= N; ++i)
    {
        if (isPrime[i])
        {
            val[i]++;
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
                val[i]++;
            }
        }
    }
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
        sieve();
        cases
        {
            ll n;
            cout << val[n];
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    //ending time of program
    return 0;
}
