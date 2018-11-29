/*#ifdef _CONSOLE
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif*/
#include<iostream>
using namespace std;

typedef long long ll;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007

int N, M;
int ans, tmp;
int a[8][8], d[8][8];

const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,-1,0,1 };

void dfs(int r, int c) {
	d[r][c] = 2;
	rep(dir, 0, 4) {
		int ty = r + dy[dir];
		int tx = c + dx[dir];
		if (0 <= ty && ty < N && 0 <= tx && tx < M && d[ty][tx] == 0) {
			dfs(ty, tx);
		}
	}
}

int proc() {
	int ret = 0;
	rep(i, 0, N) {
		rep(j, 0, M) {
			d[i][j] = a[i][j];
		}
	}

	//stack<int> s;

	rep(i, 0, N) {
		rep(j, 0, M) {
			if (d[i][j] == 2) {
				rep(dir, 0, 4) {
					int ty = i + dy[dir];
					int tx = j + dx[dir];
					if (0 <= ty && ty < N && 0 <= tx && tx < M && d[ty][tx] == 0) {
						dfs(ty, tx);
					}
				}
			}
		}
	}
	rep(i, 0, N) {
		rep(j, 0, M) {
			if (d[i][j] == 0)
				++ret;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
/*#ifdef _CONSOLE
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	// your code goes here
	cin >> N >> M;

	rep(i, 0, N) {
		rep(j, 0, M) {
			cin >> a[i][j];
		}
	}

	rep(i, 0, N*M - 2) {
		rep(j, i + 1, N*M - 1) {
			rep(k, j + 1, N*M) {
				if (a[i / M][i%M] == 0 && a[j / M][j%M] == 0 && a[k / M][k%M] == 0) {
					a[i / M][i%M] = a[j / M][j%M] = a[k / M][k%M] = 1;
					tmp = proc();
					if (ans < tmp)
						ans = tmp;
					a[i / M][i%M] = a[j / M][j%M] = a[k / M][k%M] = 0;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}