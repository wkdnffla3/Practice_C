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
		q.pop();//처리한거 큐에서 없애기.

		if (map[temp.i][temp.j])continue;//맵에 이미 방문한 경우를 패스
		map[temp.i][temp.j] = 1;
		if (IsSame(temp, d)) {
			cout << temp.step<<'\n';
			//도착했을시 출력하고 break 거는 부분
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
						q.push(temp);//1번

			temp = temp2;
			temp.i -= 1;
			temp.j -= 2;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//2번

			temp = temp2;
			temp.i += 1;
			temp.j -= 2;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//3번

			temp = temp2;
			temp.i += 2;
			temp.j -= 1;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//4번

			temp = temp2;
			temp.i += 2;
			temp.j += 1;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//5번

			temp = temp2;
			temp.i += 1;
			temp.j += 2;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//6번

			temp = temp2;
			temp.i -= 1;
			temp.j += 2;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//7번

			temp = temp2;
			temp.i -= 2;
			temp.j += 1;
			temp.step++;
			if (map[temp.i][temp.j] == 0)
				if (temp.i >= 0 && temp.i < size)
					if (temp.j >= 0 && temp.j < size)
						q.push(temp);//8번

			
			/*if (q.empty()) {
				cout << "end" << endl;
				break;
			}*/
			//temp 를 기준으로 8개 방면에 대한걸 push 해준다
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