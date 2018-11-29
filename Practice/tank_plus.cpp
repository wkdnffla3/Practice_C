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

// ÀÌµ¿ || ÀÏ¹ÝÅº
const int moveY[5] = { -1,0,0,0,1 };
const int moveX[5] = { 0,-1,0,1,0 };

// Æ¯¼öÅº
const int specialY[13] = { -2,-1,-1,-1,0,0,0,0,0,1,1,1,2 };
const int specialX[13] = { 0,-1,0,1,-2,-1,0,1,2,-1,0,1,0 };

int n, k, y, x;
double ans;
char v[300][300];

// ÀÏ¹ÝÅº
int foo1(int r, int c) {
	int ret = 0;
	rep(i, 0, 5) {
		int ty = r + moveY[i];
		int tx = c + moveX[i];
		if (0 <= ty && ty < n && 0 <= tx && tx < n && v[ty][tx] == '2')
			++ret;
	}
	return ret;
}

// Æ¯¼öÅº
int foo2(int r, int c) {
	int ret = 0;
	rep(i, 0, 13) {
		int ty = r + specialY[i];
		int tx = c + specialX[i];
		if (0 <= ty && ty < n && 0 <= tx && tx < n && v[ty][tx] == '2')
			++ret;
	}
	return ret;
}

void proc() {
	rep(i, 0, 5) {
		int ty = y + moveY[i];
		int tx = x + moveX[i];
		double tmp; // 
		rep(j, -k, k + 1) {
			int tty = j;
			int ttx = k - labs(tty);
			tmp = foo1(ty + tty, tx + ttx);
			if (ans < tmp)
				ans = tmp;
			tmp = foo1(ty + tty, tx - ttx);
			if (ans < tmp)
				ans = tmp;
			tmp = foo2(ty + tty, tx + ttx);
			if (ans < tmp / 2)
				ans = tmp / 2;
			tmp = foo2(ty + tty, tx - ttx);
			if (ans < tmp / 2)
				ans = tmp / 2;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
/*#ifdef _CONSOLE
	freopen("output_map.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	// your code goes here

	//input
	cin >> n >> k;
	rep(i, 0, n) {
		cin >> v[i];
		rep(j, 0, n) {
			if (v[i][j] == '1') {
				y = i;
				x = j;
			}
		}
	}
	//solve
	proc();

	//output
	if (ans == (int)ans)
		cout << ((int)ans) << '\n';
	else
		cout << ans << '\n';
	return 0;
}