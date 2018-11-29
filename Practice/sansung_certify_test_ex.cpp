/*
T: [1 50]
N: [4 20]
A[N][N]
Aij: [1 100]
*/
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

int T, N, ans;
int a[20][20];
int c[101];
const int dy[] = { 1,1,-1,-1 };
const int dx[] = { -1,1,1,-1 };

void input() {
	ans = 0;
	cin >> N;
	rep(i, 0, N) {
		rep(j, 0, N) {
			cin >> a[i][j];
		}
	}
}
// ↙↘↗↖
void proc(int y, int x, int dir, int ret, int cnt1, int cnt2) {
	if (dir == 3 && !cnt1 && !cnt2) {
		if (ans < ret)
			ans = ret;
		return;
	}
	if (y < 0 || y == N || x < 0 || x == N || c[a[y][x]])
		return;
	++ret;
	c[a[y][x]] = 1;
	if (dir == 3) { // cnt2 == 0 일시 시작부분에서 거른다
		proc(y + dy[dir], x + dx[dir], dir, ret, cnt1, cnt2 - 1); // ↖
	}
	else if (dir == 2) {
		if (cnt1) // ↗ 방향으로 가는 건 외길
			proc(y + dy[dir], x + dx[dir], dir, ret, cnt1 - 1, cnt2); // ↗
		else { // ↗ 방향 모두 이동 완료시 ↖
			++dir;
			proc(y + dy[dir], x + dx[dir], dir, ret, cnt1, cnt2 - 1); // ↖
		}
	}
	else if (dir == 1) {
		proc(y + dy[dir], x + dx[dir], dir, ret, cnt1, cnt2 + 1); // ↘
		if (cnt2) { // ↘ 방향으로 1번이라도 움직였다면
			++dir;
			proc(y + dy[dir], x + dx[dir], dir, ret, cnt1 - 1, cnt2); // ↗
		}
	}
	else if (dir == 0) {
		proc(y + dy[dir], x + dx[dir], dir, ret, cnt1 + 1, cnt2); // ↙ 
		if (cnt1) { // ↙ 방향으로 1번이라도 움직였다면
			++dir;
			proc(y + dy[dir], x + dx[dir], dir, ret, cnt1, cnt2 + 1); // ↘
		}
	}
	c[a[y][x]] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	
	 {
		input();
		rep(i, 0, N - 2) {
			rep(j, 1, N - 1) {
				proc(i, j, 0, 0, 0, 0);
			}
		}
		cout  << (ans ? ans : -1) << '\n';
	}
	return 0;
}