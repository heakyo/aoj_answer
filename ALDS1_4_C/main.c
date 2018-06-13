#include <stdio.h>
#include <string.h>

#define M 1000001
#define NIL -1

int T[M];

int h1(int k)
{
	return k % M;
}

int h2(int k)
{
	return (1 + (k % (M-1)));
}

int h(int k, int i)
{
	return (h1(k) + i * h2(k)) % M;
}

int insert(int key)
{
	int i = 0, p;
	while (1) {
		if (i >= M)
			return NIL;
		p = h(key, i++);
		if (NIL == T[p]) {
			T[p] = key;
			return p;
		}
	}
}

int find(int key)
{
	int i = 0, p;
	while (1) {
		if (i >= M)
			return NIL;
		p = h(key, i++);
		if (key == T[p]) {
			return p;
		} else if (NIL == T[p]) {
			return NIL;
		}
	}
}

int get_char(char ch)
{
	switch (ch) {
	case 'A': return 1;
	case 'C': return 2;
	case 'G': return 3;
	case 'T': return 4;
	default: return 0;
	}
}

int get_key(char *cargs)
{
	int key = 0, p = 1;
	while (*cargs != 0) {
		key += p * get_char(*cargs);
		p *= 5;
		cargs++;
	}
	return key;
}

int main(int argc, char *argv[])
{
	int i, n, key;
	char cmd[10], cargs[12];
	memset(T, NIL, sizeof(T));

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %s", cmd, cargs);
		key = get_key(cargs);

		if (!strcmp(cmd, "insert")) {
			insert(key);
		} else if (!strcmp(cmd, "find")) {
			if (NIL != find(key)) {
				printf("yes\n");
			} else {
				printf("no\n");
			}
		}
	}

	return 0;
}
