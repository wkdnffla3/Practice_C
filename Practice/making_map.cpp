#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int input;
	int x, y;
	int **map;

	srand(time(NULL));

	scanf("%d",&input);

	map = (int **)malloc(sizeof(int*)*input);
	for (int i = 0; i < input; i++) map[i] = (int *)malloc(sizeof(int)*input);

	for (int i = 0; i < input; i++)
		for (int j = 0; j < input; j++)
			if(rand() % 2)
			map[i][j] = 2;
			else
				map[i][j] = 0;
	x = rand() % input; y = rand() % input;
	map[x][y] = 1;
	FILE *fp;
	fp = fopen("output_map.txt", "w");
	
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++)
			fprintf(fp,"%d",map[i][j]);
		fprintf(fp,"\n");
	}
	free(map[0]);
	free(map);
	return 0;
}