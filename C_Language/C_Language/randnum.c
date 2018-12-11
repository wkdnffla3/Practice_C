#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main() {
	srand(time(NULL));
	int a = rand() % 10 +1;
	
	int input;

	
	
	for (;;) {
		scanf("%d", &input);

		if (input == a) {
			printf("correct\n");
			break;
		}
		else if (input > a)
			printf("bigger than a\n");
		else if (input < a)
			printf("smaller than a\n");
	}

	printf("done\n");

	//printf("%d", input);
	//printf("%d", a);


	return 0;
}