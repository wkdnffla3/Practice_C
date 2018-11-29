#include<iostream>
#include<algorithm>

using namespace std;


int N, T, K;
int val[200000];
void proc() {
	int score=0;
	sort(val, val + N);
	for (int i = N - 1; i > 0; i--)
	{
		if (K != 0) { score += val[i]; K--; }
		else
			break;
	}
	cout << score << endl;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> K;
		for (int j = 0; j < N; j++)
			cin >> val[j];
		cout << "Case #" << i + 1 << endl;
		proc();
	}

	return 0;
}