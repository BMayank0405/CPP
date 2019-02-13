/*
 * author: bmayank
 * URL : #{problem_url}
 */

#include <bits/stdc++.h>

//optimization of program
#define eb emplace_back
#define gc getchar_unlocked
//end of optmization

//shorten coding time
#define ll long long
#define ull unsigned long long
#define power9 1000000007
#define power5 100007
#define totalChars 25
#define P pair<int, int>
//end of shorten coding time

//helper code
#define forEach(c) for (auto &value : c)
#define loopab(loopconstant, startingValue, endingValue) for (loopconstant = (startingValue); loopconstant <= (endingValue); loopconstant++)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper)

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

    //starting time of the program
    int startTime = clock();
    //

    try
    {
        ifstream mayank("../../testCases.txt");
        mayank.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
        if (!mayank.is_open())
        {
            cerr << "Error opening file" << endl;
            exit(1);
        }

        //write your code here
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }



    //ending time of program
    int endTime = clock();

    //just to check how much time does the code takes to execute
    cout << "total execution time is " << (endTime - startTime) / double(CLOCKS_PER_SEC) << endl;

    return 0;
}
