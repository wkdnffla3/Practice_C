#include<iostream>
#include<queue>
using namespace std;
int map[100][100] = { 0 };
typedef struct Point {
	int i, j, step;
	int route[100][2];//지나온 경로 저장
}P;

bool IsSame(P s, P d) {
	if (s.i == d.i)
	{
		if (s.j == d.j)
			return true;
		else
			return false;
	}
	else
		return false;
}

void proc(P s, P d, int size) {
	for (int a = 0; a < 100; a++)for (int b = 0; b < 100; b++)map[a][b] = 0;//all map initialize to 0
	int course1 = 0;
	P temp, temp2;
	queue<P> q;
	q.push(s);
	

	for (;;) {
		temp2 = q.front();
		temp = q.front();
		q.pop();//처리한거 큐에서 없애기.

		if (map[temp.i][temp.j])continue;//맵에 이미 방문한 경우를 패스
		map[temp.i][temp.j] = 1;
		if (IsSame(temp, d)) {
			//cout << temp.step << '\n';
			course1 = temp.step;

			for (int a = 0; a < 100; a++)for (int b = 0; b < 100; b++)map[a][b] = 0;//all map initialize to 0
			for (int c = 1; c < temp.step; c++)//cout << temp.route[c][0] << ' ' << temp.route[c][1] << endl;
				map[temp.route[c][0]][temp.route[c][1]] = 1;//이미 갔던 경로 표시
			break;
		}
		else {
			temp = temp2;temp.i -= 2;temp.j -= 1;
			temp.route[temp.step][0] = temp2.i;temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)if (temp.i >= 0 && temp.i < size)if (temp.j >= 0 && temp.j < size)q.push(temp);//1번

			temp = temp2;temp.i -= 1;temp.j -= 2;
			temp.route[temp.step][0] = temp2.i;temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//2번

			temp = temp2;
			temp.i += 1;
			temp.j -= 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//3번

			temp = temp2;
			temp.i += 2;
			temp.j -= 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//4번

			temp = temp2;
			temp.i += 2;
			temp.j += 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//5번

			temp = temp2;
			temp.i += 1;
			temp.j += 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//6번

			temp = temp2;
			temp.i -= 1;
			temp.j += 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//7번

			temp = temp2;
			temp.i -= 2;
			temp.j += 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//8번
		}

	}
	
	queue<P>q2;
	q2.push(d);

	for (;;) {
		temp2 = q2.front();
		temp = q2.front();
		q2.pop();//처리한거 큐에서 없애기.

		if (map[temp.i][temp.j])continue;//맵에 이미 방문한 경우를 패스
		map[temp.i][temp.j] = 1;
		if (IsSame(temp, s)) {
			cout << temp.step+course1 << '\n';
			//course1 = temp.step;

			//for (int a = 0; a < 400; a++)for (int b = 0; b < 400; b++)map[a][b] = 0;//all map initialize to 0
			//for (int c = 1; c < temp.step; c++)//cout << temp.route[c][0] << ' ' << temp.route[c][1] << endl;
				//map[temp.route[c][0]][temp.route[c][1]] = 1;
			break;
		}
		else {
			temp = temp2;
			temp.i -= 2;
			temp.j -= 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//1번

			temp = temp2;
			temp.i -= 1;
			temp.j -= 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//2번

			temp = temp2;
			temp.i += 1;
			temp.j -= 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//3번

			temp = temp2;
			temp.i += 2;
			temp.j -= 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//4번

			temp = temp2;
			temp.i += 2;
			temp.j += 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//5번

			temp = temp2;
			temp.i += 1;
			temp.j += 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//6번

			temp = temp2;
			temp.i -= 1;
			temp.j += 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//7번

			temp = temp2;
			temp.i -= 2;
			temp.j += 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//8번
		}

	}
}

int main() {
	int entire_loop;
	cin >> entire_loop;
	int map_size;
	P starting_point, departing_point;

	for (int e_i = 0; e_i < entire_loop; e_i++) {
		int tree_index = 0;
		cin >> map_size;
		cin >> departing_point.i >> departing_point.j;
		cin >> starting_point.i >> starting_point.j;
		departing_point.step = 0; starting_point.step = 0;
		proc(starting_point, departing_point, map_size);
	}

	return 0;
}