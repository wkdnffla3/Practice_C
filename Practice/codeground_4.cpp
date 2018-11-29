#include<iostream>
#include<math.h>
#define PI 3.141592653589
using namespace std;

int N, T;
int r[5];

int score1[21] = { 6,13,13,4,4,18,18,1,1,20,20,5,5,12,12,9,9,14,14,11,11 };
int score2[21] = { 6,10,10,15,15,2,2,17,17,3,3,19,19,7,7,16,16,8,8,11,11 };
/*
r[0]은 bull 구간 반지름
r[1]~[2] 더블 구간 반지름
[3][4] 트리플 구간 반지름
*/
typedef struct POint{
	int i,j;
}P;
P p[10000];
//int p[10000];

void proc() {
	int totalscore = 0;
	int temp_score;
	double theta;
	for (int i = 0; i < N; i++) {
		theta=atan2(p[i].i, p[i].j) / PI * 180;
 		if (theta >= 0)temp_score = score1[(int)theta / 9];
		else temp_score = score2[(int)theta*-1 / 9];
		int len=p[i].i*p[i].i+p[i].j*p[i].j;
		if (len < r[0])
			temp_score = 50;
		else if (r[1] < len&&len < r[2])
			temp_score *= 3;
		else if (r[3] < len&&len<r[4])
			temp_score *= 2;
		else if (len > r[4])
			temp_score = 0;
		totalscore += temp_score;
	}
	cout << totalscore << endl;
}

int main() {
	int x, y;
	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 5; j++)
		{
			cin >> r[j];
			r[j] = r[j] * r[j];
		}
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> p[j].j >> p[j].i;
			
		}
		cout << "Case #" << i + 1 << endl;
		proc();
	}

	return 0;
}