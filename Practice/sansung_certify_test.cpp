#include<iostream>
using namespace std;

int N, map[20][20] = { 0 },fi,fj;
int mem[100] = { 0 };
int mem_index=0,save;
int check_mem(int a) {
	for (int i = 0; i < mem_index; i++) {
		if (a == mem[i])return 1;
	}
	return 0;
}
void dfs(int a, int b,int dir) {
	if (dir > 4)return;//4번 이상이면 답이 없는거므로 리턴한다.
	if (check_mem(map[a][b])) {
		return;
	}//현위치가 중복된 값인지 판단.
	if (a == fi + 1 && b == fj - 1) { 
		if(save<mem_index+1)
			save = mem_index + 1; 
		return; 
	}//네모가 완성될때
	
	if (dir == 1) {
		mem[mem_index] = map[a][b]; 
		mem_index++;
		if (a == N-1) {
			mem[mem_index - 1] = 0;
			mem_index--;
			return; 
		}//바닥에 있어서 못움직일때
		else if (b == N-1) {//벽에 있을때 노드는 1개만 생성
			if (map[a + 1][b - 1] != map[a][b])
				dfs(a + 1, b - 1, dir + 1);
		}
		else { 
			dfs(a + 1, b + 1, dir); 
		
			if (map[a + 1][b - 1] != map[a][b])
				dfs(a + 1, b - 1, dir + 1);
		}
		
	}
	else if (dir == 2) {
		mem[mem_index] = map[a][b]; 
		mem_index++;
		if (b == 0) {
			mem[mem_index - 1] = 0;
			mem_index--;
			return; 
		}//왼쪽 벽에 있어서 못움직일때
		else if (a == N-1) {//바닥에 있을때 노드는 1개만 생성
			if (map[a - 1][b - 1] != map[a][b])
				dfs(a - 1, b - 1, dir + 1);
		}
		else {
			dfs(a + 1, b - 1, dir); 
			
			if (map[a - 1][b - 1] != map[a][b])
				dfs(a - 1, b - 1, dir + 1);
		}
	
	}
	else if (dir == 3) {
		mem[mem_index] = map[a][b]; mem_index++;
		if (a == 0) {
			mem[mem_index - 1] = 0;
			mem_index--;
			return; 
		}//위쪽 벽에 있어서 못움직일때
		else if (b == 0) {//왼쪽 벽에 있을때 노드는 1개만 생성
			if (map[a - 1][b + 1] != map[a][b])
				dfs(a - 1, b + 1, dir + 1);
		}
		else {
			dfs(a - 1, b - 1, dir);
			
			if (map[a - 1][b + 1] != map[a][b])
				dfs(a - 1, b + 1, dir + 1);
		}
	
	}
	else if (dir == 4) {
		mem[mem_index] = map[a][b]; 
		mem_index++;
		if (b == N-1) {
			mem[mem_index - 1] = 0;
			mem_index--;
			return;
		}//오른쪽벽에 있어서 못움직일때
		else if (a == 0) {//왼쪽 벽에 있을때 노드는 1개만 생성
			if (map[a + 1][b + 1] != map[a][b])
				dfs(a + 1, b + 1, dir + 1);
		}
		else {
			dfs(a - 1, b + 1, dir); 
			
			if (map[a + 1][b + 1] != map[a][b])
				dfs(a + 1, b + 1, dir + 1);
		}
		
	}
	mem[mem_index - 1] = 0;
	mem_index--;
}
void proc() {
	int dir = 1;
	save = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) { 
			if (i+1<N&&j+1<N&&(map[i][j]!=map[i+1][j+1])) {
				 fi = i; fj = j;//시작위치 저장하기
				mem[mem_index] = map[i][j]; mem_index++;
				dfs(i + 1, j + 1, dir);
				mem[mem_index - 1] = 0; mem_index--;
			}
		}
	if (save == 0)cout << "-1\n";
	else  cout << save  << "\n";
}

int main() {
	int T;
	cin >> T;
	for (int g = 0; g < T; g++) {
		cin >> N;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)cin >> map[i][j];//테스트 케이스 입력끝

		proc();
	}
	return 0;
}