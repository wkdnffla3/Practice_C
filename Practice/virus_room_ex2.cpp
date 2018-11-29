#include<stdio.h>
int map[8][8], n, m;
int v[8][8];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int dfs(int x, int y) {
	int re = 1, t;
	v[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
		if (v[xx][yy] == 0 && map[xx][yy] == 0) {
			t = dfs(xx, yy);
			if (re && t) re += t;
			else re = 0;
		}
		if (map[xx][yy] == 2) re = 0;
	}
	return re;
}
int main() {
	int max = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)scanf("%d", &map[i][j]);
	for (int x = 0; x < n*m; x++)for (int y = x + 1; y < n*m; y++)for (int z = y + 1; z < n*m; z++) {
		int xi = x / m, xj = x % m;
		int yi = y / m, yj = y % m;
		int zi = z / m, zj = z % m;
		int s = 0;
		if (map[xi][xj] + map[yi][yj] + map[zi][zj] != 0) continue;
		map[xi][xj] = map[yi][yj] = map[zi][zj] = 1;
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)v[i][j] = 0;
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && v[i][j] == 0) s += dfs(i, j);
		}
		map[xi][xj] = map[yi][yj] = map[zi][zj] = 0;
		if (max < s) max = s;
	}
	printf("%d", max);
	return 0;
}