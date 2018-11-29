#include<iostream>
#include<queue>

using namespace std;

using std::cout;
using std::cin;
using std::endl;

typedef struct point {
	int h, n, m;
	int step;
}P;


int Box[100][100][100] = { 0 };
int H, N, M;

void print() {
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
				printf("%d ",Box[i][j][k]);
			printf("\n");
		}		
		printf("\n");
	}
}
/*
어떻게하지 
*/
void proc() {
	queue<P> q;
	P temp;
	int step = 1;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
				if (Box[i][j][k] == step) {
					temp.h = i; temp.n = j; temp.m = k; temp.step = step;
                 					q.push(temp);
				}
		}
	}
	P temp2;
	for (;!q.empty();) {
		temp = temp2 = q.front();
		q.pop();
		if (temp.h - 1 >= 0 && Box[temp.h - 1][temp.n][temp.m] == 0) 
		{ temp.h -= 1; 
		temp.step += 1; 
		Box[temp.h][temp.n][temp.m] = temp.step;
		q.push(temp); 
		//print();
		}//아래
		temp = temp2;
		if (temp.h + 1 < H && Box[temp.h + 1][temp.n][temp.m] == 0) { 
			temp.h += 1;
			temp.step += 1;
			Box[temp.h][temp.n][temp.m] = temp.step;
			q.push(temp); 
			//print();
		}//위
		temp = temp2;
		if (temp.n - 1 >= 0 && Box[temp.h][temp.n-1][temp.m] == 0) 
		{ temp.n -= 1; 
		temp.step += 1; 
		Box[temp.h][temp.n][temp.m] = temp.step;
		q.push(temp);
		//print();
		}//전
		temp = temp2;
		if (temp.n + 1 < N && Box[temp.h][temp.n+1][temp.m] == 0) {
			temp.n += 1;
			temp.step += 1;
			Box[temp.h][temp.n][temp.m] = temp.step;
			q.push(temp);
			//print();
		}//후
		temp = temp2;
		if (temp.m - 1 >= 0 && Box[temp.h][temp.n][temp.m-1] == 0) { 
			temp.m -= 1; 
			temp.step += 1; 
			Box[temp.h][temp.n][temp.m] = temp.step;
			q.push(temp);
			//print();
		}//좌
		temp = temp2;
		if (temp.m + 1 < M && Box[temp.h][temp.n][temp.m+1] == 0) { 
			temp.m += 1; 
			temp.step += 1;
			Box[temp.h][temp.n][temp.m] = temp.step;
			q.push(temp);
			//print();
		}//우
		temp = temp2;
		//print();
	}
	int day = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (Box[i][j][k] == 0) { printf("-1"); return; }
				if (Box[i][j][k] > day)	day=Box[i][j][k];
			}
			
		}
		
	}
	printf("%d",day-1);
}
int main() {
	
	int temp_H, temp_N, temp_M;
	cin >> M >> N >> H;
	for (temp_H = 0; temp_H < H; temp_H++) {
		for (temp_N = 0; temp_N < N; temp_N++) {
			for (temp_M = 0; temp_M < M; temp_M++)
				cin >> Box[temp_H][temp_N][temp_M];
		}
	}
	proc();
	//print();

	return 0;
}