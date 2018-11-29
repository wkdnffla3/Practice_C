#include<stdio.h>

int map[14][14] = { 0 };
int route = 0;
int size = 0;

bool Check(int r, int c) {
	int i, j;
	i = r, j = c;
	while (i >= 0 && j >= 0) {
		if (map[i--][j--])return 0;
	}
	i = r, j = c;
	while (i >= 0) {
		if (map[i--][j])return 0;
	}
	i = r, j = c;
	while (i >= 0 && j < size) {
		if (map[i--][j++])return 0;
	}
	return 1;
}
void dfs(int r, int c) {
	if (r + 1 == size) { route++; return; }//맨 끝줄에 놓은것이므로 경로 추가
	for(int i=0;i<size;i++)
	if (Check(r+1, i)) { 
		map[r + 1][i] = 1;
		dfs(r + 1, i);
		map[r + 1][i] = 0;
	}

}
int main() {
	scanf("%d",&size);
	for (int i = 0; i < size; i++) {
		map[0][i] = 1;
		dfs(0, i);
		map[0][i] = 0;
	}
	printf("%d",route);

	return 0;
}










/*#include<stdio.h.>
//위치해 있는것 1 위치했던것2 못가게 막는것 3 
int map[15][15]{ 0 };

void proc(int size);

void print(int size);

int main() {
	int input;
	
	scanf("%d",&input);
	proc(input);


	return 0;
}

void print(int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}

void proc(int size) {
	int all_counter = 0;
	for (int column=0; column < size; column++) {
		for (int raw = 0; raw < size; raw++) {
			
			if (map[column][raw] == 0) { 
				map[column][raw] = 1; 
				
				int temp_x=raw, temp_y=column;	
				for (int i = 1; temp_y + i < size; i++) {
					if (temp_x - i >= 0) {
						map[temp_y + i][temp_x - i] = 3;//왼쪽 아래
					}
					map[temp_y+i][temp_x] = 3;//중앙 아래
					if (temp_x + i < size)
						map[temp_y + i][temp_x + i] = 3;
				}//못가게 막는것
				break;//퀸을 두고 못가게 처리를 했으면 그다음줄로
			}
						
		}
		print(size);
		printf("\n");
		if (column == size - 1) {

		}
	}

}*/