#include<stdio.h>
#include<stdlib.h>

//룩을 3번만 움직여서 잡는 알고리즘....


int main() {
	int n, m;
	scanf("%d %d",&n,&m);

	char **matrix = (char **)malloc(sizeof(char *)*n);
	for (int i = 0; i < n; i++) {
		matrix[i] = (char*)malloc(sizeof(char)*m);
	}
	getchar();
	printf("%d %d\n",n,m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &matrix[i][j]);
		}
	}
	//printf("%c",matrix[0][0]);
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c1",matrix[i][j]);
		}
		printf("\n");
	}*/
	
	
	free(matrix[0]);
	free(matrix);

	return 0;
}