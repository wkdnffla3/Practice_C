#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�迭 �ȿ����� ���԰� ����
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
	memmove(arr + 5,arr+7,sizeof(arr)-sizeof(int)*7);//3ĭ�� �����ϴ� ���̹Ƿ�

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)printf("%d ",arr[i]);
	printf("\n");

	return 0;
}
//0 1 2 3 4 7 8 9 8 9
//5�� °���� 7��°�� ���� �����ͼ� ���̰� �� ũ��� ��ü���� �������� index�� �����̴�.
