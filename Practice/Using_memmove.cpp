#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//배열 안에서의 삽입과 삭제
/*
void *memmove(void *dest,const void *Src,size_t n);
first destination to copy memmory address
second real mem address
third mem size

endl
*/
int main() {
	int arr[10];
	for (int i = 0; i < 10; i++)arr[i] = i;
	memmove(arr + 5,arr+7,sizeof(arr)-sizeof(int)*7);//3칸만 복사하는 것이므로

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
//0 1 2 3 4 7 8 9 8 9
//5번 째부터 7번째의 값을 가져와서 붙이고 그 크기는 전체에서 가져오는 index를 뺀값이다.
