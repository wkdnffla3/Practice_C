#include<stdio.h>
#include<stdlib.h>

//map size is starting 0

typedef struct position {
	int i, j;
}pos;

void save_range(int range,pos set,pos save[],int *index);

void effective(pos attack[], int attack_index, float *value, int map_size);//인자와 공격범위의 전체 INDEX를 매개변수로 넣어줌 그냥 여기서 다처리 해버렷!
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
	
	save_range(1, set, can_move, &move_index);//움직이기 가능한곳 구하기
	save_range(range, set, save_attack, &can_attack_index);//can attack range when basic coordinate position 움직이지 않을때의 공격 가능한 범위 구하기.
	//구해진 범위가 맵의 밖인건 어디서 처리를 할까????????????????????????????????
	//->이미 구한건 어쩔수 없다 대신! 타격 범위를 찾을때 고정점이 맵 밖인지 안인지 판단하게 하자!!!!!!

	for (int i = 0; i < move_index; i++)
		save_range(range, can_move[i], save_attack, &can_attack_index);//이동 가능한 좌표들을 가지고 공격범위를 찾는다
	//이로써 모든 공격범위를 save_attack배열에 넣었다. 여기서 타격 판단을 시작한다.
	/*
		타격 함수의 매개변수엔 무엇을 넣어야될까
		일단 save_attack에서 인자를 받아오기!
		탄종을 구분하는 인자? 아니면 함수내에서 그냥 처리?
		효율 값을 보관하는 변수도 main문에 필요
		메모리 문제도있으니까 타격 확인은 일일히 수작업으로 (금방 끝날거야 금방............ ㅜㅜ) 13번만 돌리자......
		그럼 매개변수엔 save_attack, last_value(main에서 선언한 전역적인 효율 변수)) 이거면 되나??? 이전값이랑 이후 값이랑 비교해서 무조건 큰거 넣으면 되고
		함수 시작 부분은 save_attack에서 받아온 인자들이 -1보다 큰지 안큰지 구분해서 -1보다 크면 통과 아니면 패스...
		일반탄 구문이랑 특수탄 구문 따로.
		일반탄 구문도 범위가 맵 밖으로 나가는지 확인 필요 맨처음 부분부터 if로 걸러내기 
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
	for (i = range*-1, j = 0; j < range; i++, j++)//하단 우측방향
		//printf("%d %d\n", set.i + i, set.j + j);
	{
		save[save_index].i = set.i + i;
		save[save_index].j = set.j + j;
		save_index++;
	}

	for (i = 0, j = range; i < range; i++, j--)//하단 좌측 방향
	//	printf("%d %d\n", set.i + i, set.j + j);
	{
		save[save_index].i = set.i + i;
		save[save_index].j = set.j + j;
		save_index++;
	}

	for (i = range, j = 0; i > 0; i--, j--)//상단 좌측 방향
		//printf("%d %d\n", set.i + i, set.j + j);
	{
		save[save_index].i = set.i + i;
		save[save_index].j = set.j + j;
		save_index++;
	}

	for (i = 0, j = range*-1 ; j < 0; i--, j++)//상단 우측 방향
		//printf("%d %d\n", set.i + i, set.j + j);
	{
		save[save_index].i = set.i + i;
		save[save_index].j = set.j + j;
		save_index++;
	}
	*index = save_index;
	//printf("end1\n");
}

void effective(pos attack[], int attack_index,float *value,int map_size) {//인자와 공격범위의 전체 INDEX를 매개변수로 넣어줌 그냥 여기서 다처리 해버렷!

	pos high;//가장 높을때의 위치
	high = attack[0];

	int count = 0;
	//printf("%d %d %d \n",high.i,high.j,attack_index);
	for (int i = 0; i < attack_index; i++) {//어짜피 검사는 다하는거니 for문 안돌게 공격가능한 좌표들만 찾기
		
	
		if (attack[i].i > -1 && attack[i].j > -1) {//map 밖인거 검사하기 -1과 map크기 이상인거 찾기
			if (attack[i].i < map_size && attack[i].j <map_size)
			{
				//일반탄일때 효율

				//특수탄일때 효율

			}
		}
	}
}

