/*
 * author: bmayank
 */

#include <bits/stdc++.h>
#include <thread>
#include <mutex>
//optimization of program
#define eb emplace_back
#define gc getchar_unlocked
//end of optmization

//shorten coding time
#define ll long long
#define ull unsigned long long
#define power5 1000000007
#define power9 7
// #define power9 100007
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
mutex vectLock;

void GenerateTestCases(unsigned int start, unsigned int end, unsigned int threadnum)
{
	// cout << "Thread started for " << threadnum << endl;
	unsigned int j = 0;

	loopab(j, start, end)
	{
		unsigned int length = 1 + rand() % totalChars;
		string str = "";

		str += length;
		while (length--)
		{
			str += "1";
		}
		vectLock.lock();
		cout << str << endl;
		vectLock.unlock();
	}

	//create a lock for file
	// if (!infile.is_open())
	// {
	// 	cerr << "Error opening file" << endl;
	// 	exit(1);
	// }
}

void StrStream(unsigned int numOfThreads, unsigned int threadSpread)
{
	// cout << threadSpread << endl;
	unsigned int i = 0;
	unsigned int start = 1;
	unsigned int newEnd = start + threadSpread;
	vector<thread> threadVect;
	loop(i, numOfThreads)
	{
		// cout << "thread number " << i << endl;
		// cout << "start for " << i << " is : " << start << " end for " << i << " is : " << newEnd << endl;
		//execute each thread such that it writes to the file
		threadVect.emplace_back(GenerateTestCases,
														start, newEnd, i);

		start += threadSpread;
		newEnd += threadSpread;
	}
	for (auto &t : threadVect)
	{
		t.join();
	}
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	try
	{

		// ofstream mayank("../testcases/RandomtestCases.txt", ofstream::out | ofstream::trunc);
		// mayank.exceptions(ofstream::eofbit | ofstream::failbit | ofstream::badbit);
		// if (!mayank.is_open())
		// {
		// 	cerr << "Error opening file" << endl;
		// 	exit(1);
		// }
		srand(time(NULL));
		unsigned int testcases = 3 + rand() % power9, i, j;
		cout << "testcases : " << testcases << "\n";
		unsigned int numofThreads = 3;
		//need to improve this logic
		if (testcases <= numofThreads)
			StrStream(testcases, 1);
		else
			StrStream(numofThreads, round((double)testcases / numofThreads));
	}
	catch (exception const &e)
	{
		cout << "There was an error: " << e.what() << endl;
	}

	return 0;
}
