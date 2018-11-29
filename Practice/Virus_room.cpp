#include<iostream>
#include<queue>
typedef struct point {
	int i, j;
}P;

using namespace std;
int map[8][8] = { 0 };
int temp_map[8][8] = { 0 };
int colum, row;
int score = 0;
P p1, p2, p3;//벽의 좌표
queue<P> Q;

void print();
void proc2(P point) {
	P temp_point=point;

	if (temp_point.i - 1 > -1&&map[temp_point.i-1][temp_point.j]==0) {
		temp_point.i -= 1;
		map[temp_point.i][temp_point.j] = 2;
		Q.push(temp_point);
	}//위
	temp_point = point;
	
	if (temp_point.i + 1 <colum&&map[temp_point.i + 1][temp_point.j] == 0) {
		temp_point.i += 1;
		map[temp_point.i][temp_point.j] = 2;
		Q.push(temp_point);
	}//아래
	temp_point = point;

	if (temp_point.j - 1 > -1 && map[temp_point.i][temp_point.j-1] == 0) {
		temp_point.j -= 1;
		map[temp_point.i][temp_point.j] = 2;
		Q.push(temp_point);
	}//왼쪽
	temp_point = point;
	
	if (temp_point.j + 1 < row&& map[temp_point.i][temp_point.j + 1] == 0) {
		temp_point.j += 1;
		map[temp_point.i][temp_point.j] = 2;
		Q.push(temp_point);
	}//오른쪽
	temp_point = point;
	
	P temp;
	int step = 2;
	for (; !Q.empty();) {
		temp_point =temp = Q.front();
		Q.pop();
		if (temp_point.i - 1 > -1 && map[temp_point.i - 1][temp_point.j] == 0) {
			temp_point.i -= 1;
			map[temp_point.i][temp_point.j] = 2;
			Q.push(temp_point);
		}//위
		temp_point = temp;
		if (temp_point.i + 1 <colum&&map[temp_point.i + 1][temp_point.j] == 0) {
			temp_point.i += 1;
			map[temp_point.i][temp_point.j] = 2;
			Q.push(temp_point);
		}//아래
		temp_point = temp;

		if (temp_point.j - 1 > -1 && map[temp_point.i][temp_point.j - 1] == 0) {
			temp_point.j -= 1;
			map[temp_point.i][temp_point.j] = 2;
			Q.push(temp_point);
		}
		temp_point = temp;
		if (temp_point.j + 1 < row&& map[temp_point.i][temp_point.j + 1] == 0) {
			temp_point.j += 1;
			map[temp_point.i][temp_point.j] = 2;
			Q.push(temp_point);
		}
		temp_point = temp;
		
	}
}

void proc() {
	P temp_point;
	int counting_zero=0;
	for (int i = 0; i < colum; i++)
		for (int j = 0; j < row; j++)
			if (map[i][j] == 2)
			{
				temp_point.i = i; temp_point.j = j;
				proc2(temp_point);
			}
	for (int i = 0; i < colum; i++)
		for (int j = 0; j < row; j++)
			if (map[i][j] == 0)counting_zero++;
	print();
	
	if (score < counting_zero)score = counting_zero;
	
	
	for (int i = 0; i < colum; i++)
		for (int j = 0; j < row; j++)
			map[i][j] = temp_map[i][j];
}

void print() {
	cout << "\n";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}


int main() {
	
	cin >> colum >> row;
	for (int i = 0; i < colum; i++)
		for (int j = 0; j < row; j++)
		{
			cin >> map[i][j];
			temp_map[i][j] = map[i][j];
		}

	for (int a = 0; a < colum*row-2; a++) {
		p1.i = a / row;
		p1.j = a % row;
		if (map[p1.i][p1.j] != 0)
			continue;
		else if (map[p1.i][p1.j] == 0)
			//map[p1.i][p1.j] = 1;
		for (int b = a + 1; b < colum*row - 1; b++) {
			p2.i = b / row;
			p2.j = b % row;
			if (map[p2.i][p2.j] != 0)
				continue;
			else if (map[p2.i][p2.j] == 0)
				//map[p2.i][p2.j] = 1;
			for (int c = b + 1; c < colum*row; c++) {
				p3.i = c / row;
				p3.j = c % row;
				if (map[p3.i][p3.j] != 0)
					continue;
				else if (map[p3.i][p3.j] == 0)
				{
					map[p3.i][p3.j] = 1;
					map[p2.i][p2.j] = 1;
					map[p1.i][p1.j] = 1;
					proc();
					map[p3.i][p3.j] = 0;
					map[p2.i][p2.j] = 0;
					map[p1.i][p1.j] = 0;
				}

			}
		}
	}
	cout << score;
	return 0;
}