#include<iostream>

using namespace std;
int DP[1000001];
int N;
void proc(){
	DP[1] = DP[2] = DP[3] = 1;
	int temp, temp2,temp3;
	for (int i = 4; i <= N; i++) {
		temp = temp2 = temp3 = 0;
		if (i % 3 == 0)
			temp = i / 3;
		if (i % 2 == 0)
			temp2 = i / 2;
		temp3 = i - 1;

		if (temp != 0 && temp2 != 0) {
			if (DP[temp] >= DP[temp2])
				DP[i] = DP[temp2];
			else
				DP[i] = DP[temp];
			if (DP[i] >= DP[temp3])
				DP[i] = DP[temp3];
		}
		else if (temp == 0 && temp2 != 0) {
			if (DP[temp2] >= DP[temp3])
				DP[i] = DP[temp3];
			else DP[i] = DP[temp2];
		}
		else if (temp != 0 && temp2 == 0) {
			if (DP[temp] >= DP[temp3])
				DP[i] = DP[temp3];
			else
				DP[i] = DP[temp];
		}
		else DP[i] = DP[temp3];
		DP[i]++;
	}
	cout << DP[N];
}

int main() {
	cin >> N;
	proc();

	return 0;
}