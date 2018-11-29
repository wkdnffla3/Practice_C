#include<iostream>
#include<queue>
using namespace std;

typedef struct Point {
	int i, j, step;
	int route[100][2];
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
	int count = 0;
	P temp,temp2;
	queue<P> q;
	q.push(s);
	int j = 1;
	int map[400][400] = { 0 };

	for (;;) {
		temp2 = q.front();
		temp = q.front();
		q.pop();//ó���Ѱ� ť���� ���ֱ�.

		if (map[temp.i][temp.j])continue;//�ʿ� �̹� �湮�� ��츦 �н�
		map[temp.i][temp.j] = 1;
		if (IsSame(temp, d)) {
			cout << temp.step<<'\n';
			//���������� ����ϰ� break �Ŵ� �κ�
			//cout << count;
			break;
		}
		else {
			temp = temp2;
			temp.i -= 2;
			temp.j -= 1;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//1��

			temp = temp2;
			temp.i -= 1;
			temp.j -= 2;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//2��

			temp = temp2;
			temp.i += 1;
			temp.j -= 2;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//3��

			temp = temp2;
			temp.i += 2;
			temp.j -= 1;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//4��

			temp = temp2;
			temp.i += 2;
			temp.j += 1;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//5��

			temp = temp2;
			temp.i += 1;
			temp.j += 2;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//6��

			temp = temp2;
			temp.i -= 1;
			temp.j += 2;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//7��

			temp = temp2;
			temp.i -= 2;
			temp.j += 1;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//8��

			
			/*if (q.empty()) {
				cout << "end" << endl;
				break;
			}*/
			//temp �� �������� 8�� ��鿡 ���Ѱ� push ���ش�
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
		//if(e_i!=entire_loop-1)cout << endl;
	}

	//test for code
	/*	for (int i = 1; i < 8 * 8 * 8; i *= 8)
			for (int j = 1; j < i * 8; j++)
				if (j == i * 8 - 1)
					cout << j << endl;
	*/
	return 0;
}