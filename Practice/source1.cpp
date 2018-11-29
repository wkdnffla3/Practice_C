#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int loop;
	int sector_out, attack_unit;
	scanf("%d", &loop);
	scanf("%d %d", &sector_out, &attack_unit);

	vector<vector<int> >v(2, vector<int>(sector_out));

	for (int i = 0; i < sector_out; i++) {
		cin >> v[0][i];
	}
	for (int i = 0; i < sector_out; i++) {
		cin >> v[1][i];
	}

	for (int i = 0;;) {
		cout << v[1][i];

	}


	printf("new line");
	printf("new line 2");


	return 0;
}