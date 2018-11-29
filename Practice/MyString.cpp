#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void change_string(char *str,char *str2);
int find_length(char *str);
void change_int(int *temp) {
	*temp = 1;
}

int find_compare(char *str, char *str2);
char *My_strpbrk(char *s1, const char *delimit);
int My_strspn(char *s1, const char *delimit);

int main() {

	char str[100]="My name is Park chan gue";
	char str2[10] = "asd";
	char str3[10] = "asd";
	char str4[10] = "dsa";
	char del[10] = "nip";
	char *str_temp;
	int temp = 2;
	cout << temp << endl;
	change_int(&temp);
	cout << temp << endl;

	cout << str<<endl;

	cout << str4 << endl;;
	change_string(str4,str3);
	cout << str4 << endl;;
	
	cout << "strlen : " << find_length(str) << endl;

	cout << "strcmp : " << find_compare(str, str3)<<endl;

	str_temp = My_strpbrk(str, del);

	cout << My_strspn(str, del) << endl;

	cout << str_temp<<endl;

	return 0;
}

void change_string(char *str, char *str2) {
	for (int i = 0; str2[i] != '\0'; i++)
		str[i] = str2[i];
}
int find_length(char *str) {
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}

int find_compare(char *str, char *str2) {
	int str1_len = find_length(str);
	int str2_len = find_length(str2);
	
	if (str1_len >= str2_len) {
		for (int i = 0; i < str1_len; i++) {
			if (str[i] < str2[i]) {
				return -1;
			}
			else if (str[i] > str2[i]) {
				return 1;
			}
		}
	}
	else {
		for (int i = 0; i < str2_len; i++) {
			if (str[i] < str2[i]) {
				return -1;
			}
			else if (str[i] > str2[i]) {
				return 1;
			}
		}
	}
	return 0;
}

char *My_strtok(char *s1, const char *delimit) {
	static char *lastToken = NULL;/*UNSAFE shared state*/
	char *tmp;

	if (s1 == NULL) {
		s1 = lastToken;
		if (s1 == NULL) return NULL; /*End of story?*/
	}
	else {
		s1 += strspn(s1, delimit);
	}
	tmp = strpbrk(s1, delimit);//찾은거 이후로 나머지 반환
	if (tmp) {
		/*Found another delimiter, split string and save state*/
		*tmp = '\0';
		lastToken = tmp + 1;
	}
	else {
		/*Last segment, remember that*/
		lastToken = NULL;
	}
	return s1;
}

char *My_strpbrk(char *s1, const char *delimit) {
	for (int i = 0; s1[i]; i++) {
		for (int j = 0;delimit[j];j++)
			if (s1[i] == delimit[j]) 	return s1 + i;
	}
	return s1;
}

int My_strspn(char *s1, const char *delimit) {
	bool flag=false;
	int count = 0;
	for(int i=0;s1[i];i++)
		for (int j = 0; delimit[j]; j++) {
			if (s1[i] == delimit[j]) {
				flag = true;
				count++;
			}
			else if (flag)
				return count;
		}
}
