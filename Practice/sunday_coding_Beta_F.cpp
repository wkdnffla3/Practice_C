

#include<iostream>

using namespace std;
int N, Q[100000][3];
int A[100000] = { 0 };
int M;
int min2;
void proc() {
	for (int T = 0; T < M; T++) {
		min2 = 100000000;
		if (Q[T][0] == 2) {
			for (int i = Q[T][1]-1; i < Q[T][2] ; i++)
				if (min2 > A[i])
					min2 = A[i];
			cout << min2 << '\n';
		}
		else if (Q[T][0] == 1) {
			A[Q[T][1]-1] = Q[T][2];
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> M;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < 3; j++)
			cin >> Q[i][j];
	proc();
	return 0;
}