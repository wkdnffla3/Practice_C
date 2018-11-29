#include<stdio.h>

int input[10000];
int temp_value[10001][3] = { 0 };

int max(int a, int b) {
	if ( a >= b)
		return a;
	else return b;
}
int main() {
	int size;
	scanf("%d",&size);
	for (int i = 0; i < size; i++)scanf("%d",&input[i]);

	temp_value[1][1] = temp_value[1][2] = input[0];

	for (int i = 2; i <= size; i++) {
		temp_value[i][0] = max(max(temp_value[i - 1][0], temp_value[i - 1][1]), temp_value[i - 1][2]);
		temp_value[i][1] = temp_value[i - 1][0] + input[i-1];
		temp_value[i][2] = temp_value[i - 1][1] + input[i-1];
	}
	printf("%d",max(max(temp_value[size][0],temp_value[size][1]),temp_value[size][2]));
	return 0;
}