#include<iostream>
/*
�⺻���� �߱��� ���� �� ��Ʈ����ũ ���� 
1ball 2���庼 3����

*/
using std::cin;
using std::cout;
using std::endl;

void increase_base(int *base,int *score) {
	if (base[2] == 1)
		*score+=1;
	base[2] = base[1];
	base[1] = base[0];
	base[0] = 0;
}

int main() {
	int input[50000];
	int base[3] = { 0 };
	int score = 0;
	
	int k;//all case

	int count=0;
	
	//input code
	cin >> k;
	for (int i = 0; i < k; i++)cin >> input[i];
	
	for (int i = 0; i < k; i++) {
		//���ϰ��
		if (input[i] == 1)
			count++;
		//�����ϰ��
		else if (input[i] == 3) {
			count++;
			increase_base(base, &score);
		}
		//���庼�� ���
		else if (input[i] == 2) {
			count = 0;
			if (base[0] == 0)base[0] = 1;
			else if (base[1] == 0 && base[0] == 1) {
				base[1] = 1; base[0] = 1;
			}
			else if (base[1] == 1 && base[0] == 1) {
				increase_base(base, &score);
				base[0] = 1;
			}
			else if(base[2]==0 &&base[1]==1)increase_base(base, &score);
			else if (base[2] == 1 && base[1] == 1)increase_base(base, &score);
			//if (base[0] == 1)increase_base(base, &score);
			//else base[0] = 1;
		}
		//������ ���
		if (count == 4) {
			count = 0;
			if (base[0] == 0)base[0] = 1;
			else if (base[1] == 0 && base[0] == 1) {
				base[1] = 1; base[0] = 1;
			}
			else if (base[1] == 1 && base[0] == 1) {
				increase_base(base, &score);
				base[0] = 1;
			}
			else if (base[2] == 0&& base[1] == 1)increase_base(base, &score);
			else if (base[2] == 1 && base[1] == 1)increase_base(base, &score);
			//if (base[0] == 1)increase_base(base, &score);
			//else base[0] = 1;
		}
		
	}

	//test
	
	//for (int i = 0; i < 3; i++)cout << base[i]<<" ";
	cout <<score;

	return 0;
}