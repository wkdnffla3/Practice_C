#include<stdio.h>
#include<stdlib.h>

//map size is starting 0

typedef struct position {
	int i, j;
}pos;

void save_range(int range,pos set,pos save[],int *index);

void effective(pos attack[], int attack_index, float *value, int map_size);//���ڿ� ���ݹ����� ��ü INDEX�� �Ű������� �־��� �׳� ���⼭ ��ó�� �ع���!
int map[10][10] = {
	{ 1,1,0,1,1,1,1,0,0,0 },
	{ 1,0,0,1,0,1,0,0,0,1 },
	{ 0,1,1,2,1,1,1,0,1,1 },
	{ 0,0,1,1,1,0,0,0,1,1 },
	{ 0,1,0,0,0,1,0,1,0,0 },
	{ 1,0,0,0,0,1,0,1,1,0 },
	{ 1,0,1,0,1,1,1,0,0,1 },
	{ 1,1,0,1,1,0,0,1,1,1 },
	{ 0,1,1,0,1,0,1,1,0,0 },
	{ 0,0,0,0,0,1,0,0,1,1 },
};
int main() {
	pos set;
	set.i = 2;set.j = 2;

	
	int map_size = 10;
	//int i, j;
	int range = 3;
	int can_attack_index = 0;
	int move_index = 0;
	
	float value;
	
	pos *can_move = (pos*)malloc(sizeof(pos) * 4);//can moving all coordinate
	pos *save_attack = (pos*)malloc(sizeof(pos)*range*4*5);
	
	save_range(1, set, can_move, &move_index);//�����̱� �����Ѱ� ���ϱ�
	save_range(range, set, save_attack, &can_attack_index);//can attack range when basic coordinate position �������� �������� ���� ������ ���� ���ϱ�.
	//������ ������ ���� ���ΰ� ��� ó���� �ұ�????????????????????????????????
	//->�̹� ���Ѱ� ��¿�� ���� ���! Ÿ�� ������ ã���� �������� �� ������ ������ �Ǵ��ϰ� ����!!!!!!

	for (int i = 0; i < move_index; i++)
		save_range(range, can_move[i], save_attack, &can_attack_index);//�̵� ������ ��ǥ���� ������ ���ݹ����� ã�´�
	//�̷ν� ��� ���ݹ����� save_attack�迭�� �־���. ���⼭ Ÿ�� �Ǵ��� �����Ѵ�.
	/*
		Ÿ�� �Լ��� �Ű������� ������ �־�ߵɱ�
		�ϴ� save_attack���� ���ڸ� �޾ƿ���!
		ź���� �����ϴ� ����? �ƴϸ� �Լ������� �׳� ó��?
		ȿ�� ���� �����ϴ� ������ main���� �ʿ�
		�޸� �����������ϱ� Ÿ�� Ȯ���� ������ ���۾����� (�ݹ� �����ž� �ݹ�............ �̤�) 13���� ������......
		�׷� �Ű������� save_attack, last_value(main���� ������ �������� ȿ�� ����)) �̰Ÿ� �ǳ�??? �������̶� ���� ���̶� ���ؼ� ������ ū�� ������ �ǰ�
		�Լ� ���� �κ��� save_attack���� �޾ƿ� ���ڵ��� -1���� ū�� ��ū�� �����ؼ� -1���� ũ�� ��� �ƴϸ� �н�...
		�Ϲ�ź �����̶� Ư��ź ���� ����.
		�Ϲ�ź ������ ������ �� ������ �������� Ȯ�� �ʿ� ��ó�� �κк��� if�� �ɷ����� 
	*/
	//so we fide all attack coordinate position 
	//for(int i=0;i<can_attack_index;i++)
	//printf("%d %d\n",save_attack[i].i,save_attack[i].j);

	//printf("%d", can_attack_index);

	//for (int i = 0; i<move_index; i++)
		//printf("%d %d\n", can_move[i].i, can_move[i].j);
	effective(save_attack, can_attack_index, &value,map_size);
	free(can_move);
	free(save_attack);
	return 0;
}

void save_range(int range, pos set, pos save[],int *index) {
	int i, j;
	int save_index = *index;
	for (i = range*-1, j = 0; j < range; i++, j++)//�ϴ� ��������
		//printf("%d %d\n", set.i + i, set.j + j);
	{
		save[save_index].i = set.i + i;
		save[save_index].j = set.j + j;
		save_index++;
	}

	for (i = 0, j = range; i < range; i++, j--)//�ϴ� ���� ����
	//	printf("%d %d\n", set.i + i, set.j + j);
	{
		save[save_index].i = set.i + i;
		save[save_index].j = set.j + j;
		save_index++;
	}

	for (i = range, j = 0; i > 0; i--, j--)//��� ���� ����
		//printf("%d %d\n", set.i + i, set.j + j);
	{
		save[save_index].i = set.i + i;
		save[save_index].j = set.j + j;
		save_index++;
	}

	for (i = 0, j = range*-1 ; j < 0; i--, j++)//��� ���� ����
		//printf("%d %d\n", set.i + i, set.j + j);
	{
		save[save_index].i = set.i + i;
		save[save_index].j = set.j + j;
		save_index++;
	}
	*index = save_index;
	//printf("end1\n");
}

void effective(pos attack[], int attack_index,float *value,int map_size) {//���ڿ� ���ݹ����� ��ü INDEX�� �Ű������� �־��� �׳� ���⼭ ��ó�� �ع���!

	pos high;//���� �������� ��ġ
	high = attack[0];

	int count = 0;
	//printf("%d %d %d \n",high.i,high.j,attack_index);
	for (int i = 0; i < attack_index; i++) {//��¥�� �˻�� ���ϴ°Ŵ� for�� �ȵ��� ���ݰ����� ��ǥ�鸸 ã��
		
	
		if (attack[i].i > -1 && attack[i].j > -1) {//map ���ΰ� �˻��ϱ� -1�� mapũ�� �̻��ΰ� ã��
			if (attack[i].i < map_size && attack[i].j <map_size)
			{
				//�Ϲ�ź�϶� ȿ��

				//Ư��ź�϶� ȿ��

			}
		}
	}
}

