#include<iostream>

using namespace std;

int map[10][100];
int answer=0;

void proc(int N) {
	for (int i = 0; i < 10; i++)
		map[i][N-1] = 1;
	if (N > 1) {
		for(int j=N-2;j>=0;j--)
			for (int i = 0; i < 10; i++) {
				if (i != 0 && i != 9){
					map[i][j] = map[i + 1][j + 1] % 1000000000 + map[i - 1][j + 1] % 1000000000;
					map[i][j] = map[i][j] % 1000000000;
				}
				else if(i==0) {
					map[i][j] = map[i + 1][j + 1] % 1000000000;; map[i][j] = map[i][j] % 1000000000;
				}
				else if (i == 9) {
					map[i][j] = map[i - 1][j + 1] % 1000000000;; map[i][j] = map[i][j] % 1000000000;
				}
			}
	}
	map[0][0] = 0;
	for (int i = 0; i < 10; i++) {
		answer += map[i][0];
		answer =answer% 1000000000;
	}
	cout << answer;
}

int main() {
	int N;

	cin >> N;
	proc(N);

	return 0;
}