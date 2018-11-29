#include<iostream>
#include<queue>
using namespace std;
int map[100][100] = { 0 };
typedef struct Point {
	int i, j, step;
	int route[100][2];//������ ��� ����
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
		q.pop();//ó���Ѱ� ť���� ���ֱ�.

		if (map[temp.i][temp.j])continue;//�ʿ� �̹� �湮�� ��츦 �н�
		map[temp.i][temp.j] = 1;
		if (IsSame(temp, d)) {
			//cout << temp.step << '\n';
			course1 = temp.step;

			for (int a = 0; a < 100; a++)for (int b = 0; b < 100; b++)map[a][b] = 0;//all map initialize to 0
			for (int c = 1; c < temp.step; c++)//cout << temp.route[c][0] << ' ' << temp.route[c][1] << endl;
				map[temp.route[c][0]][temp.route[c][1]] = 1;//�̹� ���� ��� ǥ��
			break;
		}
		else {
			temp = temp2;temp.i -= 2;temp.j -= 1;
			temp.route[temp.step][0] = temp2.i;temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)if (temp.i >= 0 && temp.i < size)if (temp.j >= 0 && temp.j < size)q.push(temp);//1��

			temp = temp2;temp.i -= 1;temp.j -= 2;
			temp.route[temp.step][0] = temp2.i;temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//2��

			temp = temp2;
			temp.i += 1;
			temp.j -= 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//3��

			temp = temp2;
			temp.i += 2;
			temp.j -= 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//4��

			temp = temp2;
			temp.i += 2;
			temp.j += 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//5��

			temp = temp2;
			temp.i += 1;
			temp.j += 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//6��

			temp = temp2;
			temp.i -= 1;
			temp.j += 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//7��

			temp = temp2;
			temp.i -= 2;
			temp.j += 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//8��
		}

	}
	
	queue<P>q2;
	q2.push(d);

	for (;;) {
		temp2 = q2.front();
		temp = q2.front();
		q2.pop();//ó���Ѱ� ť���� ���ֱ�.

		if (map[temp.i][temp.j])continue;//�ʿ� �̹� �湮�� ��츦 �н�
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
						q2.push(temp);//1��

			temp = temp2;
			temp.i -= 1;
			temp.j -= 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//2��

			temp = temp2;
			temp.i += 1;
			temp.j -= 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//3��

			temp = temp2;
			temp.i += 2;
			temp.j -= 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//4��

			temp = temp2;
			temp.i += 2;
			temp.j += 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//5��

			temp = temp2;
			temp.i += 1;
			temp.j += 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//6��

			temp = temp2;
			temp.i -= 1;
			temp.j += 2;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//7��

			temp = temp2;
			temp.i -= 2;
			temp.j += 1;
			temp.route[temp.step][0] = temp2.i;
			temp.route[temp.step][1] = temp2.j;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q2.push(temp);//8��
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