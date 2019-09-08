/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	unordered_map<int, int> mp;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		mp[arr[i]]++;
	}
	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		if (k - arr[i] == arr[i])
		{
			mp[arr[i]]--;
		}
		if (mp[k - arr[i]] > 0)
		{
			cout << "YES" << endl;
			flag = true;
			break;
		}
	}
	if (!flag)
		cout << "NO";

	return 0;
}