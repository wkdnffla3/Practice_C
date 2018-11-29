#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, k;

	scanf("%d %d",&n,&k);

	int *price = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&price[i]);
	}

	long long a=0,c;
	int lowest=price[0];
	for (int i = 1; i < n; i++) {
		if (lowest > price[i])
			lowest = price[i];
	}
	//printf("%d",lowest);
	float b;
	for (int i = 0;i<n;i++ ) {
		if (price[i] == lowest)
		{
		}
		
		else if (price[i] > lowest)
		{
			b =(float) (price[i] - lowest) / k;
			c = (price[i] - lowest) / k;
			a += c;
			if (b > c)
				a = -1;
		}

		
	}
	printf("%I64d",a);


	free(price);

	return 0;
}