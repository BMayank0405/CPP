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
#define MOD unsigned int modulus = 1e9 + 7;
//end of shorten coding time

//helper code
#define frlp(c) for (auto &value : c)
#define REP(n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define Odd(n) if (n & 1)
#define cases          \
    int totalCases;    \
    cin >> totalCases; \
    while (totalCases--)
//end of helper code

//debugging code
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream testCase("names_grade.txt");
    if (testCase.is_open())
    {
        cases
        {
            int q, k;
            long long total = 0, count = 0;
            cin >> q >> k;
            int len = q;
            vector<queue<int>> v;
            while (q--)
            {
                int n;
                cin >> n;

                queue<int> que;
                while (n--)
                {
                    int st;
                    cin >> st;
                    total += st;
                    que.push(st);
                }
                v.push_back(que);
            }
            if (k > total)
            {
                cout << total << endl;
                continue;
            }
            map<int, int> minque;

            for (int i = 0; i < v.size(); i++)
            {
                minque.insert(make_pair(v[i].front(), i));
                map<int, int>::iterator it = minque.begin();
                cout << it->first << "sec : " << it->second << endl;
                v[i].pop();
            }
            while (k--)
            {
                map<int, int>::iterator it = minque.begin();
                count += it->first;
                int pos = it->second;
                minque.erase(it);
                if (!v[pos].empty())
                {
                    minque.insert(make_pair(v[pos].front(),
                                            pos));
                    v[pos].pop();
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}
