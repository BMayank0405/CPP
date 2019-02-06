/*
 * author: bmayank
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
    int fd;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    try
    {
        ofstream mayank("./RandomtestCases.txt");
        mayank.exceptions(ofstream::eofbit | ofstream::failbit | ofstream::badbit);
        if (!mayank.is_open())
        {
            cerr << "Error opening file" << endl;
            exit(1);
        }
        srand(time(NULL));
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
