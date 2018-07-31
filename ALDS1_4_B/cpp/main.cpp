#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define LEN 100000

int S[LEN];

int main(int argc, char *argv[])
{
	int n = 0, q = 0, sum = 0;
	int key = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &S[i]);

	cin >> q;
	for (int i = 0; i < q; i++) {
		scanf("%d", &key);
		if (*lower_bound(S, S + n, key) == key)
			sum++;
	}

	cout << sum << endl;

	return 0;
}
