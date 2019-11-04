#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b)
{
	return a + rand() % (b - a + 1);
}

int main(int argc, char *argv[])
{
	srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
	int n = rand(2, 10);
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
	{
		int x, y, z;
		x = rand(1, 10);
		y = rand(1, 10);
		z = rand(1, 10);

		printf("%d %d %d", x, y, z);
	}
	puts("");
}