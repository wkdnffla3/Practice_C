#include<iostream>

using namespace std;

int ant_location[1000000];
int save_ant_lotation[1000000];
int stick[1000001];//stick위에 개미가 있으면 개미는 1로 나타내고 0 과 len 일때 개미는 떨어진다.
int T, len, ants;


void fast() {
	int time=0;
	for (int i = 0; i < ants; i++)
	{
		if (len - ant_location[i] >= ant_location[i]){
			if (time <= ant_location[i])time = ant_location[i];
		}
		else {
			if (time <= len - ant_location[i])time = len - ant_location[i];
		}
	}
	cout << time<<" ";
}

void slow() {
	int low = ant_location[0];int high = ant_location[0];
	for (int i = 0; i < ants; i++) {
		if (low >= ant_location[i])
			low = ant_location[i];
		if (high <= ant_location[i])
			high = ant_location[i];
	}
	if(len-low>=high)
	cout << len - low<<endl;
	else
	{
		cout << high << endl;
	}
}

void proc(){
	fast();
	slow();
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> len >> ants;//길이와 개미의 수를 입력 받음
		for (int an = 0; an < ants; an++) {
			cin >> ant_location[an];//개미의 위치를 받음
			stick[ant_location[an]]= 1;//개미의 위치를 스틱에 넣음
		}
		proc();
	}


	return 0;
}