#include<iostream>
#include<stdio.h>

using namespace std;

int A[1000];

#define max(a, b) ((a) > (b) ? (a) : (b)) 

int find_maxv(int *A, int l, int r)
{
	int x, u, v, m;

	m = (l + r) / 2;
	if (l == r - 1) return A[l];

	u = find_maxv(A, l, m);
	v = find_maxv(A, m, r);
	x = max(u, v);

	return x;
}

int main()
{
	int x, n;

	cin >> n;
	for (int i; i < n; i++)
		scanf("%d", &A[i]);

	cout << "max value: " << find_maxv(A, 0, n) << endl;
	return 0;
}
