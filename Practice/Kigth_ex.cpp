/*#ifdef _CONSOLE
#include "bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif*/
#include<iostream>
#include<queue>
using namespace std;

typedef long long ll;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007

struct Point {
	int x, y, step;
};

const int dy[8] = { -2,-2,-1,-1,1,1,2,2 };
const int dx[8] = { -1,1,-2,2,-2,2,-1,1 };

int t, l, ans;
int sx, sy, ex, ey;

void proc() {
	cin >> l;
	vector<vector<int>> c(l, vector<int>(l));
	queue<Point> q;
	cin >> sx >> sy >> ex >> ey;
	Point temp;
	temp.x = sx;
	temp.y = sy;
	temp.step = 0;
	q.push(temp);

	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (c[temp.x][temp.y])continue; // ÀÌ¹Ì ¹âÀº °÷
		if (temp.x == ex && temp.y == ey) {
			cout << temp.step << '\n';
			return;
		}
		c[temp.x][temp.y] = 1;
		rep(dir, 0, 8) {
			Point tPoint;
			tPoint.x = temp.x + dx[dir];
			tPoint.y = temp.y + dy[dir];
			tPoint.step = temp.step + 1;
			if (0 <= tPoint.x && tPoint.x < l && 0 <= tPoint.y && tPoint.y < l && !c[tPoint.x][tPoint.y])
				q.push(tPoint);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef _CONSOLE
	freopen("sample.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// your code goes here
	cin >> t;
	rep(x, 1, t + 1) {
		proc();
	}
	return 0;
}