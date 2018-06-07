#include <stdio.h>

#define MAX (10000 + 1)

int S[MAX];

int search(int *S, int n, int key)
{
	int i = 0;
	S[n] = key;
	while (S[i] != key) i++;

	return i != n;
}

int main(int argc, char *argv[])
{
	int n, q, i, key, same = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &S[i]);

	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%d", &key);
		if (search(S, n, key)) same++;
	}

	printf("%d\n", same);

	return 0;
}
