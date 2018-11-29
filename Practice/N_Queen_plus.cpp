#include <stdio.h>

int N, a[14][14], ans;
bool check(int r, int c) {
	int i, j;
	i = r, j = c;
	while (i >= 0 && j >= 0) {
		if (a[i--][j--])return 0;
	}
	i = r, j = c;
	while (i >= 0) {
		if (a[i--][j])return 0;
	}
	i = r, j = c;
	while (i >= 0 && j < N) {
		if (a[i--][j++])return 0;
	}
	return 1;
}

void dfs(int r, int c) {
	if (r == N - 1) {
		++ans;
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (check(r + 1, i)) {
			a[r + 1][i] = 1;
			dfs(r + 1, i);
			a[r + 1][i] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		a[0][i] = 1;
		dfs(0, i);
		a[0][i] = 0;
	}
	printf("%d\n", ans);
	return 0;
}