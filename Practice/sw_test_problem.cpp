#include<iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct save {
	int M, P, R;
	int result;
	int check;
}S;
S s[50];

int main() {
	int size, T;
	cin >> size >> T;
	for (int i = 0; i < size; i++)
	{
		cin >> s[i].M >> s[i].P >> s[i].R;
		s[i].result = s[i].M - s[i].P*s[i].R;
		s[i].check = 0;
	}
	int value[50];
	int find = 0;
	int time=0;
	int index;
	for (;;) {
		index = -1;
		for (int i = 0; i < size; i++)
			if (find < s[i].result&&s[i].result != -1) {
				find = s[i].result;
				index = i;
			}
		//�ִ밪�ΰ� ã�� ó�� ���ϸ� result���� -1�־ ���ǹ� �ɷ�����
		
	}

	return 0;
}