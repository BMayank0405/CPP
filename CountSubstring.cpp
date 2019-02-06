/*
 * author: bmayank
 * URL : https://www.codechef.com/problems/CSUB
 */

#include <bits/stdc++.h>

//optimization of program
#define eb emplace_back
#define gc getchar_unlocked
//end of optmization

//shorten coding time
#define ll long long
#define ull unsigned long long
#define MOD unsigned int modulus = 1e9 + 7
#define P pair<int, int>
//end of shorten coding time

//helper code
#define frlp(c) for (const auto &value : c)
#define REP(n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define Odd(n) if (n & 1)
#define cases \
    int t;    \
    cin >> t; \
    while (t--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    try
    {
        ifstream mayank("./testCases.txt");
        mayank.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
        if (!mayank.is_open())
        {
            cerr << "Error opening file" << endl;
            exit(1);
        }

        int t;
        mayank >> t;
        while (t--)
        {
            int len, count = 0;
            string str;
            mayank >> len;
            mayank >> str;
            REP(len)
            {
                if (str[i] == '1')
                {
                    count++;
                    for (int j = i + 1; j < len; j++)
                    {
                        if (str[j] == '1')
                            count++;
                    }
                }
            }
            cout << count << "\n";
        }
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
