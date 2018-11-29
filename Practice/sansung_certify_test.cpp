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
	if (dir > 4)return;//4�� �̻��̸� ���� ���°ŹǷ� �����Ѵ�.
	if (check_mem(map[a][b])) {
		return;
	}//����ġ�� �ߺ��� ������ �Ǵ�.
	if (a == fi + 1 && b == fj - 1) { 
		if(save<mem_index+1)
			save = mem_index + 1; 
		return; 
	}//�׸� �ϼ��ɶ�
	
	if (dir == 1) {
		mem[mem_index] = map[a][b]; 
		mem_index++;
		if (a == N-1) {
			mem[mem_index - 1] = 0;
			mem_index--;
			return; 
		}//�ٴڿ� �־ �������϶�
		else if (b == N-1) {//���� ������ ���� 1���� ����
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
		}//���� ���� �־ �������϶�
		else if (a == N-1) {//�ٴڿ� ������ ���� 1���� ����
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
		}//���� ���� �־ �������϶�
		else if (b == 0) {//���� ���� ������ ���� 1���� ����
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
		}//�����ʺ��� �־ �������϶�
		else if (a == 0) {//���� ���� ������ ���� 1���� ����
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
				 fi = i; fj = j;//������ġ �����ϱ�
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
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)cin >> map[i][j];//�׽�Ʈ ���̽� �Է³�

		proc();
	}
	return 0;
}