#include <stdio.h>

int binary_search(int *A, int n, int key)
{
	int left, right, mid;
	left = 0;
	right = n;
	while (left < right) {
		mid = (left + right) / 2;
		if (A[mid] == key) return 1;
		if (A[mid] < key) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int S[100000], key, i, n, q, sum = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &S[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &key);
		if (binary_search(S, n, key))
			sum++;
	}

	printf("%d\n", sum);

	return 0;
}
