#include<iostream>

using namespace std;
int price[10][10] = { 0 };
int map[10][10] = { 0 };
int total_price = 3000;
int temp_price = 0;
int N;
int m_i[5] = { 0, 0,1,0,-1 };
int m_j[5] = { 0,-1,0,1,0 };

typedef struct P {
	int i, j;
}P;
P p1, p2, p3;
bool p1b, p2b, p3b;
void proc() {
	p1b = p2b = p3b = false;
	for (int a = 0; a < (N - 2)*(N - 2) - 2; a++) {
		p1.i = a / (N - 2)+1;
		p1.j = a % (N - 2) + 1;

		for (int t = 0; t < 5; t++) {
			if (map[p1.i + m_i[t]][p1.j + m_j[t]] == 0)
			{ }
			else {		
				p3b = true;
				break;
			}
		}	if (p3b) { p3b = false; continue; }
		for (int i = 0; i < 5; i++)
			map[p1.i + m_i[i]][p1.j + m_j[i]] = 1;
		for (int b = a + 1; b < (N - 2)*(N - 2) - 1; b++) {
			p2.i = b / (N - 2) + 1;
			p2.j = b % (N - 2) + 1;

			for (int t = 0; t < 5; t++) {
				if (map[p2.i + m_i[t]][p2.j + m_j[t]] == 0)
				{ }
				else {
					
					p1b = true;
					break;
				}
			}
			if(p1b)
			{
				p1b = false;
				continue;
			}
			for (int i = 0; i < 5; i++)
				map[p2.i + m_i[i]][p2.j + m_j[i]] = 1;
			for (int c = b + 1; c < (N - 2)*(N - 2); c++) {
				p3.i = c / (N - 2) + 1;
				p3.j = c % (N - 2) + 1;
				for (int t = 0; t < 5; t++) {
					if (map[p3.i + m_i[t]][p3.j + m_j[t]] == 0)
					{ }
					else {
						p2b = true;
						break;
					}
				}
				if (p2b) { p2b = false; continue; }
				for (int i = 0; i < 5; i++)
					map[p3.i + m_i[i]][p3.j + m_j[i]] = 1;
				// 이자리에서 땅값 계산
				for (int i = 0; i < 5; i++)
					temp_price += price[p1.i + m_i[i]][p1.j + m_j[i]];
				for (int i = 0; i < 5; i++)
					temp_price += price[p2.i + m_i[i]][p2.j + m_j[i]];
				for (int i = 0; i < 5; i++)
					temp_price += price[p3.i + m_i[i]][p3.j + m_j[i]];
				if (total_price > temp_price)
					total_price = temp_price;
				temp_price = 0;
				for (int i = 0; i < 5; i++)
					map[p3.i + m_i[i]][p3.j + m_j[i]] = 0;
			}
			for (int i = 0; i < 5; i++)
				map[p2.i + m_i[i]][p2.j + m_j[i]] = 0;
		}
		for (int i = 0; i < 5; i++)
			map[p1.i + m_i[i]][p1.j + m_j[i]] = 0;

	}
	cout << total_price;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> price[i][j];
	proc();

	return 0;
}