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
#define power9 1000000007
// #define power9 7
#define power5 100007
#define totalChars 25
// #define MOD 5
#define P pair<int, int>
//end of shorten coding time

//helper code
#define for_each(c) for (auto &value : c)
#define loopab(loopconstant, startingValue, endingValue) for (loopconstant = (startingValue); loopconstant < (endingValue); loopconstant++)
#define loop(loopconstant1, stopper) loopab(loopconstant1, 0, stopper)

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
        //this code will open the file and remove the previous content stored in the file
        ofstream mayank("./RandomtestCases.txt", ofstream::out | ofstream::trunc);
        mayank.exceptions(ofstream::eofbit | ofstream::failbit | ofstream::badbit);
        if (!mayank.is_open())
        {
            cerr << "Error opening file" << endl;
            exit(1);
        }
        srand(time(NULL));
        int testcases = 1 + rand() % power9, i, j;
        stringstream finalStr;
        finalStr << testcases << "\n";

        while (testcases--)
        {
            int length = 1 + rand() % totalChars;

            finalStr << length << "\n";
            string str = "";
            while (length--)
            {
                str += "1";
            }
            //work on here to check if string is full and if string stream is full try to clear string stream based on that
            mayank << finalStr.str();
            mayank << str << "\n";
            finalStr.str("");
            finalStr.clear();
        }
        // mayank << finalStr.str();
    }
    catch (exception const &e)
    {
        cout << "There was an error: " << e.what() << endl;
    }

    return 0;
}
