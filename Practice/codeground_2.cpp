#include<iostream>
#include<algorithm>
using namespace std;
int T, N;
int val[3000000];

void proc() {
	
	int value = 0;
	for (int i = 0; i < N; i++)
		value = value^val[i];
	cout << value << endl;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++)
	
			cin >> val[j];
	
		cout << "Case #" << i + 1 << endl;
		proc();
	}

	return 0;
}